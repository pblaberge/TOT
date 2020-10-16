#pragma once

#include <cstdint>

namespace atomic {

std::int32_t AddInt32(std::int32_t* addr, std::int32_t delta);
std::int64_t AddInt64(std::int64_t* addr, std::int64_t delta);
std::uint32_t AddUint32(std::uint32_t* addr, std::uint32_t delta);
std::uint64_t AddUint64(std::uint64_t* addr, std::uint64_t delta);

bool CompareAndSwapInt32(std::int32_t* addr, std::int32_t old, std::int32_t n);
bool CompareAndSwapInt64(std::int64_t* addr, std::int64_t old, std::int64_t n);
bool CompareAndSwapUint32(std::uint32_t* addr, std::uint32_t old,
                          std::uint32_t n);
bool CompareAndSwapUint64(std::uint64_t* addr, std::uint64_t old,
                          std::uint64_t n);

std::int32_t LoadInt32(std::int32_t* addr);
std::int64_t LoadInt64(std::int64_t* addr);
std::uint32_t LoadUint32(std::uint32_t* addr);
std::uint64_t LoadUint64(std::uint64_t* addr);

void StoreInt32(std::int32_t* addr, std::int32_t val);
void StoreInt64(std::int64_t* addr, std::int64_t val);
void StoreUint32(std::uint32_t* addr, std::uint32_t val);
void StoreUint64(std::uint64_t* addr, std::uint64_t val);

std::int32_t SwapInt32(std::int32_t* addr, std::int32_t n);
std::int64_t SwapInt64(std::int64_t* addr, std::int64_t n);
std::uint32_t SwapUint32(std::uint32_t* addr, std::uint32_t n);
std::uint64_t SwapUint64(std::uint64_t* addr, std::uint64_t n);

}  // namespace atomic
