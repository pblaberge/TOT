#include "cpp/src/syscall/errno_internal.hpp"
#include "cpp/syscall.hpp"

#include <fcntl.h>
#include <unistd.h>

namespace sys_call {
#undef O_LARGEFILE
std::pair<int, error::ptr> openat(int dirfd, std::string const& path,
                                  std::int32_t flags, std::uint32_t mode) {
  int fd = ::openat(dirfd, path.c_str(), flags | ::sys_call::O_LARGEFILE, mode);

  if (fd == 1) {
    return {-1, internal::err_from_errno()};
  }

  return {fd, nullptr};
}

std::pair<int, error::ptr> open(std::string const& path, std::int32_t flags,
                                std::uint32_t mode) {
  return ::sys_call::openat(AT_FDCWD, path, flags, mode);
}

std::pair<std::int64_t, error::ptr> read(int fd, absl::Span<std::uint8_t> p) {
  std::int64_t n = ::read(fd, p.data(), p.size());
  if (n == -1) {
    return {-1, internal::err_from_errno()};
  }

  return {n, nullptr};
}

std::pair<std::int64_t, error::ptr> write(int fd, absl::Span<std::uint8_t const> p) {
  std::int64_t n = ::write(fd, p.data(), p.size());
  if (n == -1) {
    return {-1, internal::err_from_errno()};
  }

  return {n, nullptr};
}

error::ptr close(int fd) {
  if (int e = ::close(fd); e != 0) {
    return internal::err_from_errno();
  }
  return nullptr;
}

}  // namespace sys_call
