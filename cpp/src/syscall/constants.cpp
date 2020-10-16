#include "cpp/syscall.hpp"

#include <fcntl.h>
#include <sys/stat.h>

namespace {

constexpr std::uint32_t LOCAL_O_ACCMODE = O_ACCMODE;
constexpr std::uint32_t LOCAL_O_APPEND = O_APPEND;
constexpr std::uint32_t LOCAL_O_ASYNC = O_ASYNC;
constexpr std::uint32_t LOCAL_O_CLOEXEC = O_CLOEXEC;
constexpr std::uint32_t LOCAL_O_CREAT = O_CREAT;
constexpr std::uint32_t LOCAL_O_DIRECT = O_DIRECT;
constexpr std::uint32_t LOCAL_O_DIRECTORY = O_DIRECTORY;
constexpr std::uint32_t LOCAL_O_DSYNC = O_DSYNC;
constexpr std::uint32_t LOCAL_O_EXCL = O_EXCL;
constexpr std::uint32_t LOCAL_O_FSYNC = O_FSYNC;
constexpr std::uint32_t LOCAL_O_LARGEFILE = O_LARGEFILE;
constexpr std::uint32_t LOCAL_O_NDELAY = O_NDELAY;
constexpr std::uint32_t LOCAL_O_NOATIME = O_NOATIME;
constexpr std::uint32_t LOCAL_O_NOCTTY = O_NOCTTY;
constexpr std::uint32_t LOCAL_O_NOFOLLOW = O_NOFOLLOW;
constexpr std::uint32_t LOCAL_O_NONBLOCK = O_NONBLOCK;
constexpr std::uint32_t LOCAL_O_RDONLY = O_RDONLY;
constexpr std::uint32_t LOCAL_O_RDWR = O_RDWR;
constexpr std::uint32_t LOCAL_O_RSYNC = O_RSYNC;
constexpr std::uint32_t LOCAL_O_SYNC = O_SYNC;
constexpr std::uint32_t LOCAL_O_TRUNC = O_TRUNC;
constexpr std::uint32_t LOCAL_O_WRONLY = O_WRONLY;
constexpr std::uint32_t LOCAL_S_BLKSIZE = S_BLKSIZE;
constexpr std::uint32_t LOCAL_S_IEXEC = S_IEXEC;
constexpr std::uint32_t LOCAL_S_IFBLK = S_IFBLK;
constexpr std::uint32_t LOCAL_S_IFCHR = S_IFCHR;
constexpr std::uint32_t LOCAL_S_IFDIR = S_IFDIR;
constexpr std::uint32_t LOCAL_S_IFIFO = S_IFIFO;
constexpr std::uint32_t LOCAL_S_IFLNK = S_IFLNK;
constexpr std::uint32_t LOCAL_S_IFMT = S_IFMT;
constexpr std::uint32_t LOCAL_S_IFREG = S_IFREG;
constexpr std::uint32_t LOCAL_S_IFSOCK = S_IFSOCK;
constexpr std::uint32_t LOCAL_S_IREAD = S_IREAD;
constexpr std::uint32_t LOCAL_S_IRGRP = S_IRGRP;
constexpr std::uint32_t LOCAL_S_IROTH = S_IROTH;
constexpr std::uint32_t LOCAL_S_IRUSR = S_IRUSR;
constexpr std::uint32_t LOCAL_S_IRWXG = S_IRWXG;
constexpr std::uint32_t LOCAL_S_IRWXO = S_IRWXO;
constexpr std::uint32_t LOCAL_S_IRWXU = S_IRWXU;
constexpr std::uint32_t LOCAL_S_ISGID = S_ISGID;
constexpr std::uint32_t LOCAL_S_ISUID = S_ISUID;
constexpr std::uint32_t LOCAL_S_ISVTX = S_ISVTX;
constexpr std::uint32_t LOCAL_S_IWGRP = S_IWGRP;
constexpr std::uint32_t LOCAL_S_IWOTH = S_IWOTH;
constexpr std::uint32_t LOCAL_S_IWRITE = S_IWRITE;
constexpr std::uint32_t LOCAL_S_IWUSR = S_IWUSR;
constexpr std::uint32_t LOCAL_S_IXGRP = S_IXGRP;
constexpr std::uint32_t LOCAL_S_IXOTH = S_IXOTH;
constexpr std::uint32_t LOCAL_S_IXUSR = S_IXUSR;

}  // namespace

#undef O_ACCMODE
#undef O_APPEND
#undef O_ASYNC
#undef O_CLOEXEC
#undef O_CREAT
#undef O_DIRECT
#undef O_DIRECTORY
#undef O_DSYNC
#undef O_EXCL
#undef O_FSYNC
#undef O_LARGEFILE
#undef O_NDELAY
#undef O_NOATIME
#undef O_NOCTTY
#undef O_NOFOLLOW
#undef O_NONBLOCK
#undef O_RDONLY
#undef O_RDWR
#undef O_RSYNC
#undef O_SYNC
#undef O_TRUNC
#undef O_WRONLY
#undef S_BLKSIZE
#undef S_IEXEC
#undef S_IFBLK
#undef S_IFCHR
#undef S_IFDIR
#undef S_IFIFO
#undef S_IFLNK
#undef S_IFMT
#undef S_IFREG
#undef S_IFSOCK
#undef S_IREAD
#undef S_IRGRP
#undef S_IROTH
#undef S_IRUSR
#undef S_IRWXG
#undef S_IRWXO
#undef S_IRWXU
#undef S_ISGID
#undef S_ISUID
#undef S_ISVTX
#undef S_IWGRP
#undef S_IWOTH
#undef S_IWRITE
#undef S_IWUSR
#undef S_IXGRP
#undef S_IXOTH
#undef S_IXUSR

namespace sys_call {
const std::uint32_t O_ACCMODE = LOCAL_O_ACCMODE;
const std::uint32_t O_APPEND = LOCAL_O_APPEND;
const std::uint32_t O_ASYNC = LOCAL_O_ASYNC;
const std::uint32_t O_CLOEXEC = LOCAL_O_CLOEXEC;
const std::uint32_t O_CREAT = LOCAL_O_CREAT;
const std::uint32_t O_DIRECT = LOCAL_O_DIRECT;
const std::uint32_t O_DIRECTORY = LOCAL_O_DIRECTORY;
const std::uint32_t O_DSYNC = LOCAL_O_DSYNC;
const std::uint32_t O_EXCL = LOCAL_O_EXCL;
const std::uint32_t O_FSYNC = LOCAL_O_FSYNC;
const std::uint32_t O_LARGEFILE = LOCAL_O_LARGEFILE;
const std::uint32_t O_NDELAY = LOCAL_O_NDELAY;
const std::uint32_t O_NOATIME = LOCAL_O_NOATIME;
const std::uint32_t O_NOCTTY = LOCAL_O_NOCTTY;
const std::uint32_t O_NOFOLLOW = LOCAL_O_NOFOLLOW;
const std::uint32_t O_NONBLOCK = LOCAL_O_NONBLOCK;
const std::uint32_t O_RDONLY = LOCAL_O_RDONLY;
const std::uint32_t O_RDWR = LOCAL_O_RDWR;
const std::uint32_t O_RSYNC = LOCAL_O_RSYNC;
const std::uint32_t O_SYNC = LOCAL_O_SYNC;
const std::uint32_t O_TRUNC = LOCAL_O_TRUNC;
const std::uint32_t O_WRONLY = LOCAL_O_WRONLY;
const std::uint32_t S_BLKSIZE = LOCAL_S_BLKSIZE;
const std::uint32_t S_IEXEC = LOCAL_S_IEXEC;
const std::uint32_t S_IFBLK = LOCAL_S_IFBLK;
const std::uint32_t S_IFCHR = LOCAL_S_IFCHR;
const std::uint32_t S_IFDIR = LOCAL_S_IFDIR;
const std::uint32_t S_IFIFO = LOCAL_S_IFIFO;
const std::uint32_t S_IFLNK = LOCAL_S_IFLNK;
const std::uint32_t S_IFMT = LOCAL_S_IFMT;
const std::uint32_t S_IFREG = LOCAL_S_IFREG;
const std::uint32_t S_IFSOCK = LOCAL_S_IFSOCK;
const std::uint32_t S_IREAD = LOCAL_S_IREAD;
const std::uint32_t S_IRGRP = LOCAL_S_IRGRP;
const std::uint32_t S_IROTH = LOCAL_S_IROTH;
const std::uint32_t S_IRUSR = LOCAL_S_IRUSR;
const std::uint32_t S_IRWXG = LOCAL_S_IRWXG;
const std::uint32_t S_IRWXO = LOCAL_S_IRWXO;
const std::uint32_t S_IRWXU = LOCAL_S_IRWXU;
const std::uint32_t S_ISGID = LOCAL_S_ISGID;
const std::uint32_t S_ISUID = LOCAL_S_ISUID;
const std::uint32_t S_ISVTX = LOCAL_S_ISVTX;
const std::uint32_t S_IWGRP = LOCAL_S_IWGRP;
const std::uint32_t S_IWOTH = LOCAL_S_IWOTH;
const std::uint32_t S_IWRITE = LOCAL_S_IWRITE;
const std::uint32_t S_IWUSR = LOCAL_S_IWUSR;
const std::uint32_t S_IXGRP = LOCAL_S_IXGRP;
const std::uint32_t S_IXOTH = LOCAL_S_IXOTH;
const std::uint32_t S_IXUSR = LOCAL_S_IXUSR;

const int Stdin = 0;
const int Stdout = 1;
const int Stderr = 2;

}  // namespace sys_call
