#include "cpp/os.hpp"
#include "cpp/src/os/utils.hpp"
#include "cpp/syscall.hpp"

namespace os {
struct file {
  using ptr = std::unique_ptr<file>;
  std::int64_t fd;
  std::string name;
  bool appendMode;
};

File::File() = default;
File::~File() = default;

File::File(File&& other) noexcept = default;
File& File::operator=(File&& other) noexcept = default;

namespace {

file::ptr newFile(std::int64_t fd, std::string name) {
  return std::make_unique<file>(file{
      .fd = fd,
      .name = name,
  });
}

std::pair<file::ptr, error::ptr> openFile(std::string name, std::int32_t flag,
                                          FileMode perm) {
  int fd = -1;
  while (1) {
    auto [r, e] = sys_call::open(name, flag | sys_call::O_CLOEXEC,
                                 internal::syscallMode(perm));
    if (e == nullptr) {
      fd = r;
      break;
    }

    if (error::Is<sys_call::EINTR>(e)) {
      continue;
    }

    return {nullptr, std::make_unique<ErrPath>("open", std::move(name), std::move(e))};
  }

  return {newFile(fd, std::move(name)), nullptr};
}

error::ptr close(file* f) {
    return sys_call::close(f->fd);
}

std::pair<std::uint32_t, error::ptr> read(file* f, absl::Span<std::uint8_t> b)
{
    auto [n, e] = sys_call::read(f->fd, b);
    if (e != nullptr) {
        return {0, std::move(e)};
    }
    if (n < 0) {
        return {0, error::New("read: unexpected error")};
    }
    if (n == 0) {
        return {0, error::New("EOF")};
    }
    return {static_cast<std::uint32_t>(n), nullptr};
}

std::pair<std::uint32_t, error::ptr> write(file* f, absl::Span<std::uint8_t const> b)
{
    auto [n, e] = sys_call::write(f->fd, b);
    if (e != nullptr) {
        return {0, std::move(e)};
    }
    if (n < 0) {
        return {0, error::New("read: unexpected error")};
    }
    return {static_cast<std::uint32_t>(n), nullptr};
}


}  // namespace

File File::NewFile(std::int64_t fd, std::string name) {
  File f;
  f.f = newFile(fd, std::move(name));
  return f;
}

std::pair<File, error::ptr> File::OpenFile(std::string name, std::int32_t flag, FileMode perm)
{
    auto [f, e] = openFile(std::move(name), flag, perm);

    if (e != nullptr) {
        return {File{}, std::move(e)};
    }

    f->appendMode = (flag & O_APPEND) != 0; 
    File rv;
    rv.f = std::move(f);
    return {std::move(rv), nullptr};
}

std::pair<File, error::ptr> File::Open(std::string name)
{
    return OpenFile(std::move(name), O_RDONLY, FileMode(0));
}

std::pair<File, error::ptr> File::Create(std::string name)
{
    return OpenFile(std::move(name), O_RDWR|O_CREATE|O_TRUNC, FileMode(0666));
}

error::ptr File::Close()
{
    return close(f.get());
}

std::pair<uint32_t, error::ptr> File::Read(absl::Span<std::uint8_t> b)
{
   return read(f.get(), b);
}

std::pair<uint32_t, error::ptr> File::Write(absl::Span<std::uint8_t const> b)
{
   return write(f.get(), b);
}

}  // namespace os
