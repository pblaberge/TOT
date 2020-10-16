#pragma once

#include <array>
#include <memory>

#include "absl/types/span.h"
#include "cpp/error.hpp"

namespace sys_call {

// Constants
extern const std::uint32_t O_ACCMODE;
extern const std::uint32_t O_APPEND;
extern const std::uint32_t O_ASYNC;
extern const std::uint32_t O_CLOEXEC;
extern const std::uint32_t O_CREAT;
extern const std::uint32_t O_DIRECT;
extern const std::uint32_t O_DIRECTORY;
extern const std::uint32_t O_DSYNC;
extern const std::uint32_t O_EXCL;
extern const std::uint32_t O_FSYNC;
extern const std::uint32_t O_LARGEFILE;
extern const std::uint32_t O_NDELAY;
extern const std::uint32_t O_NOATIME;
extern const std::uint32_t O_NOCTTY;
extern const std::uint32_t O_NOFOLLOW;
extern const std::uint32_t O_NONBLOCK;
extern const std::uint32_t O_RDONLY;
extern const std::uint32_t O_RDWR;
extern const std::uint32_t O_RSYNC;
extern const std::uint32_t O_SYNC;
extern const std::uint32_t O_TRUNC;
extern const std::uint32_t O_WRONLY;
extern const std::uint32_t S_BLKSIZE;
extern const std::uint32_t S_IEXEC;
extern const std::uint32_t S_IFBLK;
extern const std::uint32_t S_IFCHR;
extern const std::uint32_t S_IFDIR;
extern const std::uint32_t S_IFIFO;
extern const std::uint32_t S_IFLNK;
extern const std::uint32_t S_IFMT;
extern const std::uint32_t S_IFREG;
extern const std::uint32_t S_IFSOCK;
extern const std::uint32_t S_IREAD;
extern const std::uint32_t S_IRGRP;
extern const std::uint32_t S_IROTH;
extern const std::uint32_t S_IRUSR;
extern const std::uint32_t S_IRWXG;
extern const std::uint32_t S_IRWXO;
extern const std::uint32_t S_IRWXU;
extern const std::uint32_t S_ISGID;
extern const std::uint32_t S_ISUID;
extern const std::uint32_t S_ISVTX;
extern const std::uint32_t S_IWGRP;
extern const std::uint32_t S_IWOTH;
extern const std::uint32_t S_IWRITE;
extern const std::uint32_t S_IWUSR;
extern const std::uint32_t S_IXGRP;
extern const std::uint32_t S_IXOTH;
extern const std::uint32_t S_IXUSR;

extern const int Stdin;
extern const int Stdout;
extern const int Stderr;

// Errors

class Errno : public error {
 public:
  using ptr = std::unique_ptr<Errno>;

  Errno();

  ~Errno() override;
};

#define ERRNO_CLASS(X)              \
  class X final : public Errno {    \
   public:                          \
    using ptr = std::unique_ptr<X>; \
    X();                            \
    ~X() final;                     \
    std::string Error() final;      \
  };

#undef E2BIG
#undef EACCES
#undef EADDRINUSE
#undef EADDRNOTAVAIL
#undef EAFNOSUPPORT
#undef EAGAIN
#undef EALREADY
#undef EBADE
#undef EBADF
#undef EBADFD
#undef EBADMSG
#undef EBADR
#undef EBADRQC
#undef EBADSLT
#undef EBUSY
#undef ECANCELED
#undef ECHILD
#undef ECHRNG
#undef ECOMM
#undef ECONNABORTED
#undef ECONNREFUSED
#undef ECONNRESET
#undef EDEADLK
#undef EDEADLOCK
#undef EDESTADDRREQ
#undef EDOM
#undef EDQUOT
#undef EEXIST
#undef EFAULT
#undef EFBIG
#undef EHOSTDOWN
#undef EHOSTUNREACH
#undef EHWPOISON
#undef EIDRM
#undef EILSEQ
#undef EINPROGRESS
#undef EINTR
#undef EINVAL
#undef EIO
#undef EISCONN
#undef EISDIR
#undef EISNAM
#undef EKEYEXPIRED
#undef EKEYREJECTED
#undef EKEYREVOKED
#undef EL2HLT
#undef EL2NSYNC
#undef EL3HLT
#undef EL3RST
#undef ELIBACC
#undef ELIBBAD
#undef ELIBMAX
#undef ELIBSCN
#undef ELIBEXEC
#undef ELNRANGE
#undef ELOOP
#undef EMEDIUMTYPE
#undef EMFILE
#undef EMLINK
#undef EMSGSIZE
#undef EMULTIHOP
#undef ENAMETOOLONG
#undef ENETDOWN
#undef ENETRESET
#undef ENETUNREACH
#undef ENFILE
#undef ENOANO
#undef ENOBUFS
#undef ENODATA
#undef ENODEV
#undef ENOENT
#undef ENOEXEC
#undef ENOKEY
#undef ENOLCK
#undef ENOLINK
#undef ENOMEDIUM
#undef ENOMEM
#undef ENOMSG
#undef ENONET
#undef ENOPKG
#undef ENOPROTOOPT
#undef ENOSPC
#undef ENOSR
#undef ENOSTR
#undef ENOSYS
#undef ENOTBLK
#undef ENOTCONN
#undef ENOTDIR
#undef ENOTEMPTY
#undef ENOTRECOVERABLE
#undef ENOTSOCK
#undef ENOTSUP
#undef ENOTTY
#undef ENOTUNIQ
#undef ENXIO
#undef EOPNOTSUPP
#undef EOVERFLOW
#undef EOWNERDEAD
#undef EPERM
#undef EPFNOSUPPORT
#undef EPIPE
#undef EPROTO
#undef EPROTONOSUPPORT
#undef EPROTOTYPE
#undef ERANGE
#undef EREMCHG
#undef EREMOTE
#undef EREMOTEIO
#undef ERESTART
#undef ERFKILL
#undef EROFS
#undef ESHUTDOWN
#undef ESPIPE
#undef ESOCKTNOSUPPORT
#undef ESRCH
#undef ESTALE
#undef ESTRPIPE
#undef ETIME
#undef ETIMEDOUT
#undef ETOOMANYREFS
#undef ETXTBSY
#undef EUCLEAN
#undef EUNATCH
#undef EUSERS
#undef EWOULDBLOCK
#undef EXDEV
#undef EXFULL

ERRNO_CLASS(E2BIG)
ERRNO_CLASS(EACCES)
ERRNO_CLASS(EADDRINUSE)
ERRNO_CLASS(EADDRNOTAVAIL)
ERRNO_CLASS(EAFNOSUPPORT)
ERRNO_CLASS(EAGAIN)
ERRNO_CLASS(EALREADY)
ERRNO_CLASS(EBADE)
ERRNO_CLASS(EBADF)
ERRNO_CLASS(EBADFD)
ERRNO_CLASS(EBADMSG)
ERRNO_CLASS(EBADR)
ERRNO_CLASS(EBADRQC)
ERRNO_CLASS(EBADSLT)
ERRNO_CLASS(EBUSY)
ERRNO_CLASS(ECANCELED)
ERRNO_CLASS(ECHILD)
ERRNO_CLASS(ECHRNG)
ERRNO_CLASS(ECOMM)
ERRNO_CLASS(ECONNABORTED)
ERRNO_CLASS(ECONNREFUSED)
ERRNO_CLASS(ECONNRESET)
ERRNO_CLASS(EDEADLK)
ERRNO_CLASS(EDEADLOCK)
ERRNO_CLASS(EDESTADDRREQ)
ERRNO_CLASS(EDOM)
ERRNO_CLASS(EDQUOT)
ERRNO_CLASS(EEXIST)
ERRNO_CLASS(EFAULT)
ERRNO_CLASS(EFBIG)
ERRNO_CLASS(EHOSTDOWN)
ERRNO_CLASS(EHOSTUNREACH)
ERRNO_CLASS(EHWPOISON)
ERRNO_CLASS(EIDRM)
ERRNO_CLASS(EILSEQ)
ERRNO_CLASS(EINPROGRESS)
ERRNO_CLASS(EINTR)
ERRNO_CLASS(EINVAL)
ERRNO_CLASS(EIO)
ERRNO_CLASS(EISCONN)
ERRNO_CLASS(EISDIR)
ERRNO_CLASS(EISNAM)
ERRNO_CLASS(EKEYEXPIRED)
ERRNO_CLASS(EKEYREJECTED)
ERRNO_CLASS(EKEYREVOKED)
ERRNO_CLASS(EL2HLT)
ERRNO_CLASS(EL2NSYNC)
ERRNO_CLASS(EL3HLT)
ERRNO_CLASS(EL3RST)
ERRNO_CLASS(ELIBACC)
ERRNO_CLASS(ELIBBAD)
ERRNO_CLASS(ELIBMAX)
ERRNO_CLASS(ELIBSCN)
ERRNO_CLASS(ELIBEXEC)
ERRNO_CLASS(ELNRANGE)
ERRNO_CLASS(ELOOP)
ERRNO_CLASS(EMEDIUMTYPE)
ERRNO_CLASS(EMFILE)
ERRNO_CLASS(EMLINK)
ERRNO_CLASS(EMSGSIZE)
ERRNO_CLASS(EMULTIHOP)
ERRNO_CLASS(ENAMETOOLONG)
ERRNO_CLASS(ENETDOWN)
ERRNO_CLASS(ENETRESET)
ERRNO_CLASS(ENETUNREACH)
ERRNO_CLASS(ENFILE)
ERRNO_CLASS(ENOANO)
ERRNO_CLASS(ENOBUFS)
ERRNO_CLASS(ENODATA)
ERRNO_CLASS(ENODEV)
ERRNO_CLASS(ENOENT)
ERRNO_CLASS(ENOEXEC)
ERRNO_CLASS(ENOKEY)
ERRNO_CLASS(ENOLCK)
ERRNO_CLASS(ENOLINK)
ERRNO_CLASS(ENOMEDIUM)
ERRNO_CLASS(ENOMEM)
ERRNO_CLASS(ENOMSG)
ERRNO_CLASS(ENONET)
ERRNO_CLASS(ENOPKG)
ERRNO_CLASS(ENOPROTOOPT)
ERRNO_CLASS(ENOSPC)
ERRNO_CLASS(ENOSR)
ERRNO_CLASS(ENOSTR)
ERRNO_CLASS(ENOSYS)
ERRNO_CLASS(ENOTBLK)
ERRNO_CLASS(ENOTCONN)
ERRNO_CLASS(ENOTDIR)
ERRNO_CLASS(ENOTEMPTY)
ERRNO_CLASS(ENOTRECOVERABLE)
ERRNO_CLASS(ENOTSOCK)
ERRNO_CLASS(ENOTSUP)
ERRNO_CLASS(ENOTTY)
ERRNO_CLASS(ENOTUNIQ)
ERRNO_CLASS(ENXIO)
ERRNO_CLASS(EOPNOTSUPP)
ERRNO_CLASS(EOVERFLOW)
ERRNO_CLASS(EOWNERDEAD)
ERRNO_CLASS(EPERM)
ERRNO_CLASS(EPFNOSUPPORT)
ERRNO_CLASS(EPIPE)
ERRNO_CLASS(EPROTO)
ERRNO_CLASS(EPROTONOSUPPORT)
ERRNO_CLASS(EPROTOTYPE)
ERRNO_CLASS(ERANGE)
ERRNO_CLASS(EREMCHG)
ERRNO_CLASS(EREMOTE)
ERRNO_CLASS(EREMOTEIO)
ERRNO_CLASS(ERESTART)
ERRNO_CLASS(ERFKILL)
ERRNO_CLASS(EROFS)
ERRNO_CLASS(ESHUTDOWN)
ERRNO_CLASS(ESPIPE)
ERRNO_CLASS(ESOCKTNOSUPPORT)
ERRNO_CLASS(ESRCH)
ERRNO_CLASS(ESTALE)
ERRNO_CLASS(ESTRPIPE)
ERRNO_CLASS(ETIME)
ERRNO_CLASS(ETIMEDOUT)
ERRNO_CLASS(ETOOMANYREFS)
ERRNO_CLASS(ETXTBSY)
ERRNO_CLASS(EUCLEAN)
ERRNO_CLASS(EUNATCH)
ERRNO_CLASS(EUSERS)
ERRNO_CLASS(EWOULDBLOCK)
ERRNO_CLASS(EXDEV)
ERRNO_CLASS(EXFULL)

#undef ERRNO_CLASS

// Syscalls

error::ptr pipe2(absl::Span<int> pipefd, std::int32_t flags);
std::pair<int, error::ptr> openat(int dirfd, std::string const& path,
                                  std::int32_t flags, std::uint32_t mode);
std::pair<int, error::ptr> open(std::string const& path, std::int32_t flags,
                                std::uint32_t mode);
std::pair<std::int64_t, error::ptr> read(int fd, absl::Span<std::uint8_t> p);
std::pair<std::int64_t, error::ptr> write(int fd, absl::Span<std::uint8_t const> p);
error::ptr close(int fd);

struct Timespec {
  std::int64_t Sec;
  std::int64_t NSec;

  std::int64_t Nano();
  std::pair<std::int64_t, std::int64_t> Unix();
};

Timespec NsecToTimespec(std::int64_t Nsec);

struct Stat_t {
  std::uint64_t Dev;
  std::uint64_t Ino;
  std::uint64_t Nlink;
  std::uint64_t Rdev;
  std::int64_t Size;
  std::int64_t Blksize;
  std::int64_t Blocks;
  Timespec Atim;
  Timespec Mtim;
  Timespec Ctim;
  std::uint32_t Mode;
  std::uint32_t Uid;
  std::uint32_t Gid;
};

error::ptr fstat(int fd, Stat_t* stat);
error::ptr stat(std::string const& path, Stat_t* stat);
error::ptr lstat(std::string const& path, Stat_t* stat);

}  // namespace sys_call
