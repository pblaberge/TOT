#include "cpp/os.hpp"
#include "cpp/syscall.hpp"

namespace os {

FileInfo::~FileInfo() = default;

namespace {

class FileStat final : public virtual FileInfo {
 public:
  FileStat() = default;
  ~FileStat() final = default;

  std::string Name() const final;
  std::int64_t Size() const final;
  FileMode Mode() const final;
  absl::Time ModTime() const final;
  bool IsDir() const final;

  std::string name;
  std::int64_t size;
  FileMode mode;
  absl::Time modTime;
  sys_call::Stat_t sys;
};

std::string FileStat::Name() const { return name; }

std::int64_t FileStat::Size() const { return size; }

FileMode FileStat::Mode() const { return mode; }

absl::Time FileStat::ModTime() const { return modTime; }

bool FileStat::IsDir() const { return ::os::IsDir(Mode()); }

absl::string_view basename(absl::string_view name) {
  std::uint64_t i = name.size() - 1;

  // Remove trailing slashes
  for (; i > 0 && name[i] == '/'; --i) {
    name = name.substr(0, i);
  }

  // Remove leading directory name
  for (--i; i >= 0; --i) {
    if (name[i] == '/') {
      name = name.substr(i + 1);
      break;
    }
  }
  return name;
}

absl::Time timespecToTime(sys_call::Timespec ts) {
  return absl::FromUnixNanos(ts.Nano());
}

void fillFileStatFromSys(FileStat* f, std::string const& name) {
  f->name = basename(name);
  f->size = f->sys.Size;
  f->modTime = timespecToTime(f->sys.Mtim);
  f->mode = FileMode(f->sys.Mode & 0777);

  const FileMode sys_ifmt =
      static_cast<FileMode>(f->sys.Mode & sys_call::S_IFMT);

  if (sys_ifmt == sys_call::S_IFBLK) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeDevice);
  } else if (sys_ifmt == sys_call::S_IFCHR) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeDevice |
                                    FileMode::kModeCharDevice);
  } else if (sys_ifmt == sys_call::S_IFDIR) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeDir);
  } else if (sys_ifmt == sys_call::S_IFIFO) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeNamedPipe);
  } else if (sys_ifmt == sys_call::S_IFLNK) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeSymlink);
  } else if (sys_ifmt == sys_call::S_IFREG) {
    // Do nothing
  } else if (sys_ifmt == sys_call::S_IFSOCK) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeSocket);
  } else {
    // Do nothing
  }

  if ((f->sys.Mode & sys_call::S_ISGID) != 0) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeSetgid);
  }
  if ((f->sys.Mode & sys_call::S_ISUID) != 0) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeSetuid);
  }
  if ((f->sys.Mode & sys_call::S_ISVTX) != 0) {
    f->mode = static_cast<FileMode>(f->mode | FileMode::kModeSticky);
  }
}

}  // namespace

bool IsDir(FileMode m) { return (m & FileMode::kModeDir) != 0; }

bool IsRegular(FileMode m) { return (m & FileMode::kModeType) == 0; }

FileMode Perm(FileMode m) { return FileMode(m & FileMode::kModePerm); }

std::pair<FileInfo::ptr, error::ptr> Stat(std::string const& path) {
  auto fs = std::make_unique<FileStat>();

  if (error::ptr e = ::sys_call::stat(path, &fs->sys); e != nullptr) {
    return {nullptr, std::make_unique<ErrPath>("stat", path, std::move(e))};
  }

  fillFileStatFromSys(fs.get(), path);

  return {std::move(fs), nullptr};
}

std::pair<FileInfo::ptr, error::ptr> Lstat(std::string const& path) {
  auto fs = std::make_unique<FileStat>();

  if (error::ptr e = ::sys_call::stat(path, &fs->sys); e != nullptr) {
    return {nullptr, std::make_unique<ErrPath>("lstat", path, std::move(e))};
  }

  fillFileStatFromSys(fs.get(), path);

  return {std::move(fs), nullptr};
}

}  // namespace os
