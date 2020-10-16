#pragma once

#include <cstdint>

#include "absl/strings/string_view.h"
#include "absl/time/time.h"
#include "absl/types/span.h"
#include "cpp/error.hpp"

namespace os {

class File;

// Constants

// Exactly one of O_RDONLY, O_WRONLY, or O_RDWR must be specified.
extern const std::int32_t O_RDONLY;  // open the file read-only.
extern const std::int32_t O_WRONLY;  // open the file write-only.
extern const std::int32_t O_RDWR;    // open the file read-write.

// The remaining values may be or'ed in to control behavior.
extern const std::int32_t O_APPEND;  // append data to the file when writing.
extern const std::int32_t O_CREATE;  // create a new file if none exists.
extern const std::int32_t O_EXCL;    // used with O_CREATE, file must not exist.
extern const std::int32_t O_SYNC;    // open for synchronous I/O.
extern const std::int32_t
    O_TRUNC;  // truncate regular writable file when opened.

extern const absl::string_view DevNull;

// Variables

extern File Stdin;
extern File Stdout;
extern File Stderr;

// Errors

class ErrInvalid final : public error {
 public:
  ~ErrInvalid() final;

  std::string Error() final;
};

class ErrPermission final : public error {
 public:
  ~ErrPermission() final;

  std::string Error() final;
};

class ErrExist final : public error {
 public:
  ~ErrExist() final;

  std::string Error() final;
};

class ErrNotExist final : public error {
 public:
  ~ErrNotExist() final;

  std::string Error() final;
};

class ErrClosed final : public error {
 public:
  ~ErrClosed() final;
  std::string Error() final;
};

class ErrNoDeadline final : public error {
 public:
  ~ErrNoDeadline() final;

  std::string Error() final;
};

class ErrDeadlineExceeded final : public error {
 public:
  ~ErrDeadlineExceeded() final;

  std::string Error() final;
};

class ErrPath final : public error {
 public:
  ErrPath(std::string op, std::string path, error::ptr e);
  ~ErrPath() final;

  std::string Error() final;

 private:
  std::string op;
  std::string path;
  error::ptr e;
};

// File

enum FileMode : std::uint32_t {
  kModeDir = 1U << 31,
  kModeAppend = 1U << 30,
  kModeExclusive = 1U << 29,
  kModeTemporary = 1U << 28,
  kModeSymlink = 1U << 27,
  kModeDevice = 1U << 26,
  kModeNamedPipe = 1U << 25,
  kModeSocket = 1U << 24,
  kModeSetuid = 1U << 23,
  kModeSetgid = 1U << 22,
  kModeCharDevice = 1U << 21,
  kModeSticky = 1U << 20,
  kModeIrregular = 1U << 19,
  kModeType = kModeDir | kModeSymlink | kModeNamedPipe | kModeSocket |
              kModeDevice | kModeCharDevice | kModeIrregular,
  kModePerm = 0777,
};

bool IsDir(FileMode m);
bool IsRegular(FileMode m);
FileMode Perm(FileMode m);

class FileInfo {
 public:
  using ptr = std::unique_ptr<FileInfo>;
  virtual ~FileInfo();

  virtual std::string Name() const = 0;
  virtual std::int64_t Size() const = 0;
  virtual FileMode Mode() const = 0;
  virtual absl::Time ModTime() const = 0;
  virtual bool IsDir() const = 0;
};

struct file; // OS specific implementation

class File
{
    public:
        File(File const& other) = delete;
        File& operator=(File const& other) = delete;

        File(File&& other) noexcept;
        File& operator=(File&& other) noexcept;

        ~File();

        static File NewFile(std::int64_t fd, std::string name);
        static std::pair<File, error::ptr> OpenFile(std::string name, std::int32_t flag, FileMode perm);
        static std::pair<File, error::ptr> Open(std::string name);
        static std::pair<File, error::ptr> Create(std::string name);

        error::ptr Close();

        std::pair<uint32_t, error::ptr> Read(absl::Span<std::uint8_t> b); 
        std::pair<uint32_t, error::ptr> Write(absl::Span<std::uint8_t const> b); 

    private:
        File();
        std::unique_ptr<file> f;
};

// Syscall

std::pair<FileInfo::ptr, error::ptr> Stat(std::string const& path);
std::pair<FileInfo::ptr, error::ptr> Lstat(std::string const& path);

}  // namespace os
