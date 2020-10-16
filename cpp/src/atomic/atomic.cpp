#include "cpp/atomic.hpp"

namespace atomic {

std::int32_t AddInt32(std::int32_t* addr, std::int32_t delta) {
  return __sync_add_and_fetch(addr, delta);
}

std::int64_t AddInt64(std::int64_t* addr, std::int64_t delta) {
  return __sync_add_and_fetch(addr, delta);
}

std::uint32_t AddUint32(std::uint32_t* addr, std::uint32_t delta) {
  return __sync_add_and_fetch(addr, delta);
}

std::uint64_t AddUint64(std::uint64_t* addr, std::uint64_t delta) {
  return __sync_add_and_fetch(addr, delta);
}

bool CompareAndSwapInt32(std::int32_t* addr, std::int32_t old, std::int32_t n) {
  return __sync_bool_compare_and_swap(addr, old, n);
}

bool CompareAndSwapInt64(std::int64_t* addr, std::int64_t old, std::int64_t n) {
  return __sync_bool_compare_and_swap(addr, old, n);
}

bool CompareAndSwapUint32(std::uint32_t* addr, std::uint32_t old,
                          std::uint32_t n) {
  return __sync_bool_compare_and_swap(addr, old, n);
}

bool CompareAndSwapUint64(std::uint64_t* addr, std::uint64_t old,
                          std::uint64_t n) {
  return __sync_bool_compare_and_swap(addr, old, n);
}

std::int32_t LoadInt32(std::int32_t* addr) {
  std::int32_t rv = *addr;
  __sync_synchronize();
  return rv;
}

std::int64_t LoadInt64(std::int64_t* addr) {
  std::int64_t rv = *addr;
  __sync_synchronize();
  return rv;
}

std::uint32_t LoadUint32(std::uint32_t* addr) {
  std::uint32_t rv = *addr;
  __sync_synchronize();
  return rv;
}

std::uint64_t LoadUint64(std::uint64_t* addr) {
  std::uint64_t rv = *addr;
  __sync_synchronize();
  return rv;
}

void StoreInt32(std::int32_t* addr, std::int32_t val) {
  *addr = val;
  __sync_synchronize();
  return;
}

void StoreInt64(std::int64_t* addr, std::int64_t val) {
  *addr = val;
  __sync_synchronize();
  return;
}

void StoreUint32(std::uint32_t* addr, std::uint32_t val) {
  *addr = val;
  __sync_synchronize();
  return;
}

void StoreUint64(std::uint64_t* addr, std::uint64_t val) {
  *addr = val;
  __sync_synchronize();
  return;
}

std::int32_t SwapInt32(std::int32_t* addr, std::int32_t n) {
  return __sync_lock_test_and_set(addr, n);
}

std::int64_t SwapInt64(std::int64_t* addr, std::int64_t n) {
  return __sync_lock_test_and_set(addr, n);
}

std::uint32_t SwapUint32(std::uint32_t* addr, std::uint32_t n) {
  return __sync_lock_test_and_set(addr, n);
}

std::uint64_t SwapUint64(std::uint64_t* addr, std::uint64_t n) {
  return __sync_lock_test_and_set(addr, n);
}

}  // namespace atomic
