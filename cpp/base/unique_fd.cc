#include "cpp/base/unique_fd.h"

#include <unistd.h>

namespace base
{
   UniqueFD::~UniqueFD()
   {
      close(fd_);
   }
}
