#pragma once

#include <functional>
#include <mutex>

namespace sync {

class Mutex {
 public:
  Mutex();
  Mutex(Mutex const& other) = delete;
  Mutex& operator=(Mutex const& other) = delete;
  ~Mutex();

  void lock();
  void unlock();

 private:
  std::mutex m;
};

class Once {
 public:
  Once();
  Once(Once const& other) = delete;
  Once& operator=(Once const& other) = delete;
  ~Once();

  void Do(std::function<void()> f);

 private:
  void do_slow(std::function<void()> f);

  std::uint32_t done;
  Mutex m;
};

}  // namespace sync
