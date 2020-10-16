#pragma once

#include "cpp/error.hpp"

namespace sys_call
{
namespace internal
{

error::ptr err_from_errno();

}
}
