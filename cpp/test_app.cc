#include "cpp/os.hpp"

#include <array>

int main()
{
    auto [f, err] = os::File::Open("/home/plaberge/projects/TOT/cpp/test_app.cc");

    std::array<std::uint8_t, 256> buf;

    err = nullptr;
    do {
        auto [n, e] = f.Read({buf.data(), buf.size()});
        err = std::move(e);
        if (n > 0) {
            auto [m, err2] = os::Stdout.Write({buf.data(), n});
        }
    } while (err == nullptr);

    f.Close();

    return 0;
}
