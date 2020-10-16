#include "cpp/sync.hpp"

#include "cpp/atomic.hpp"

namespace sync
{

    Once::Once() = default;
    Once::~Once() = default;

    void Once::Do(std::function<void()> f) {
        if (atomic::LoadUint32(&done) == 0) {
            do_slow(std::move(f));
        }
    }

    void Once::do_slow(std::function<void()> f) {
        std::lock_guard<Mutex> l(m);
        if (done == 0) {
            f();
            atomic::StoreUint32(&done, 1);
        }
    }
}
