#include "cpp/syscall.hpp"

namespace sys_call {

Timespec NsecToTimespec(std::int64_t nsec) {
  constexpr std::int64_t factor = 1e9;
  std::int64_t sec = nsec / factor;
  nsec = nsec % factor;

  if (nsec < 0) {
    nsec += factor;
    --sec;
  }

  return Timespec{
      .Sec = sec,
      .NSec = nsec,
  };
}

std::int64_t Timespec::Nano() {
  constexpr std::int64_t factor = 1e9;
  return (Sec * factor) + NSec;
}

std::pair<std::int64_t, std::int64_t> Timespec::Unix() {
    return {Sec, NSec};
}

}  // namespace sys_call
