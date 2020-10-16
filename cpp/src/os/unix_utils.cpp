#include "cpp/src/os/utils.hpp"

#include "cpp/syscall.hpp"

#include <unistd.h>
#include <fcntl.h>

namespace os
{
namespace internal
{

#undef O_NONBLOCK
std::pair<bool, error::ptr> isNonBlock(int fd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    if (flag == -1) {
        return {false, error::New("Could not query file")};
    }
    return {(flag & sys_call::O_NONBLOCK) != 0, nullptr};
}

}
}
