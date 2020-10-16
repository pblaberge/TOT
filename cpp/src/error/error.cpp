#include "cpp/error.hpp"

error::error() = default;
error::~error() = default;

namespace {

class BasicError : public error
{
    public:
    BasicError(std::string m);
    ~BasicError() override;

    std::string Error() final;

    private:
        std::string msg;
};

BasicError::BasicError(std::string m) : msg{std::move(m)} {}
BasicError::~BasicError() = default;

std::string BasicError::Error() {
    return msg;
}

}

error::ptr error::New(std::string msg) {
    return std::make_unique<BasicError>(std::move(msg));
}
