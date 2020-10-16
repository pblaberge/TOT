#include "cpp/syscall.hpp"
#include "cpp/src/syscall/errno_internal.hpp"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace sys_call {

namespace {

void kernelStruct2StatT(Stat_t* to, struct stat const * from) {
    to->Dev = from->st_dev;
    to->Ino = from->st_ino;
    to->Nlink = from->st_nlink;
    to->Mode = from->st_mode;
    to->Uid = from->st_uid;
    to->Gid = from->st_gid;
    to->Rdev = from->st_rdev;
    to->Size = from->st_size;
    to->Blksize = from->st_blksize;
    to->Blocks = from->st_blocks;

    to->Atim = Timespec{
        .Sec = from->st_atim.tv_sec,
        .NSec = from->st_atim.tv_nsec,
    };
    to->Mtim = Timespec{
        .Sec = from->st_mtim.tv_sec,
        .NSec = from->st_mtim.tv_nsec,
    };
    to->Ctim = Timespec{
        .Sec = from->st_ctim.tv_sec,
        .NSec = from->st_ctim.tv_nsec,
    };
}

error::ptr fstatat(int dirfd, std::string const& path, Stat_t* s, int flags)
{
    struct stat stat_kernel_struct;

    if (int e = ::fstatat(dirfd, path.c_str(), &stat_kernel_struct, flags); e != 0) {
        return internal::err_from_errno(); 
    }

    kernelStruct2StatT(s, &stat_kernel_struct);

    return nullptr;

}

}

error::ptr fstat(int fd, Stat_t* s)
{
    struct stat stat_kernel_struct;

    if (int e = ::fstat(fd, &stat_kernel_struct); e != 0) {
        return internal::err_from_errno(); 
    }

    kernelStruct2StatT(s, &stat_kernel_struct);

    return nullptr;
}

error::ptr stat(std::string const& path, Stat_t* stat)
{
    return fstatat(AT_FDCWD, path, stat, 0);
}

error::ptr lstat(std::string const& path, Stat_t* stat)
{
    return fstatat(AT_FDCWD, path, stat, AT_SYMLINK_NOFOLLOW);
}


}
