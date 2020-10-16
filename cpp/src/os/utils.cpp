#include "cpp/src/os/utils.hpp"

#include "cpp/syscall.hpp"

namespace os
{
namespace internal
{

std::uint32_t syscallMode(FileMode i)
{
    std::uint32_t o = 0;
    o |= static_cast<std::uint32_t>(Perm(i));
    if (i&kModeSetuid) {
        o |= sys_call::S_ISUID;
    }
    if (i&kModeSetgid) {
        o |= sys_call::S_ISGID;
    }
    if (i&kModeSticky) {
        o |= sys_call::S_ISVTX;
    }
    return o;
}

}
}
