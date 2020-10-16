#include "cpp/sync.hpp"

namespace sync
{

Mutex::Mutex() = default;
Mutex::~Mutex() = default;

void Mutex::lock() {
    m.lock();
}

void Mutex::unlock() {
    m.unlock();
}

}
