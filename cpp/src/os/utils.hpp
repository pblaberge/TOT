#pragma once

#include "cpp/os.hpp"

namespace os
{
namespace internal
{

std::uint32_t syscallMode(FileMode i);

std::pair<bool, error::ptr> isNonBlock(int fd);

}
}
