#include "cpp/os.hpp"

#include "cpp/syscall.hpp"

namespace os {

const std::int32_t O_RDONLY = sys_call::O_RDONLY;  
const std::int32_t O_WRONLY = sys_call::O_WRONLY;  
const std::int32_t O_RDWR = sys_call::O_RDWR;    
const std::int32_t O_APPEND = sys_call::O_APPEND;  
const std::int32_t O_CREATE = sys_call::O_CREAT;  
const std::int32_t O_EXCL = sys_call::O_EXCL;    
const std::int32_t O_SYNC = sys_call::O_SYNC;    
const std::int32_t O_TRUNC = sys_call::O_TRUNC;

const absl::string_view DevNull = "/dev/null";

File Stdin = File::NewFile(sys_call::Stdin, "/dev/stdin");
File Stdout = File::NewFile(sys_call::Stdout, "/dev/stdout");
File Stderr = File::NewFile(sys_call::Stderr, "/dev/stderr");

}  // namespace os
