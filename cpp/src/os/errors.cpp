#include "cpp/os.hpp"

#include "absl/strings/str_cat.h"

namespace {
    constexpr const char kErrInvalid[] = "invalid argument";
    constexpr const char kErrPermission[] = "permission denied";
    constexpr const char kErrExist[] = "file already exists";
    constexpr const char kErrNotExist[] = "file does not exist";
    constexpr const char kErrClosed[] = "file already closed";
    constexpr const char kErrNoDeadline[] = "file type does not support deadline";
    constexpr const char kErrDeadlineExceeded[] = "i/o timeout";
}

namespace os
{
    ErrInvalid::~ErrInvalid() = default;

    std::string ErrInvalid::Error() {
        return kErrInvalid;
    }

    ErrPermission::~ErrPermission() = default;

    std::string ErrPermission::Error() {
        return kErrPermission;
    }

    ErrExist::~ErrExist() = default;

    std::string ErrExist::Error() {
        return kErrExist;
    }

    ErrNotExist::~ErrNotExist() = default;

    std::string ErrNotExist::Error() {
        return kErrNotExist;
    }

    ErrClosed::~ErrClosed() = default;

    std::string ErrClosed::Error() {
        return kErrClosed;
    }

    ErrNoDeadline::~ErrNoDeadline() = default;

    std::string ErrNoDeadline::Error() {
        return kErrNoDeadline;
    }

    ErrDeadlineExceeded::~ErrDeadlineExceeded() = default;

    std::string ErrDeadlineExceeded::Error() {
        return kErrDeadlineExceeded;
    }

    ErrPath::ErrPath(std::string op_, std::string path_, error::ptr e_)
        : op{std::move(op_)}, path{std::move(path_)}, e{std::move(e_)} {}

    ErrPath::~ErrPath() = default;

    std::string ErrPath::Error() {
        return absl::StrCat(op, " ", path,  ": ",  e->Error());
    }

}
