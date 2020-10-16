#include "cpp/syscall.hpp"

#include <unistd.h>

#include "cpp/src/syscall/errno_internal.hpp"

namespace sys_call
{

#undef EINVAL
error::ptr pipe2(absl::Span<int> pipefd, std::int32_t flags)
{
    if (pipefd.size() != 2) {
        return std::make_unique<EINVAL>();
    }

    if (int e = ::pipe2(pipefd.data(), flags); e != 0) {
        return internal::err_from_errno();
    }

    return nullptr;
}
    
}
