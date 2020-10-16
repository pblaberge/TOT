#include "cpp/base/error.h"

error::error() = default;
error::~error() = default;

namespace {

class WrappedError : public virtual error
{
public:
	using ptr = std::unique_ptr<WrappedError>;

	WrappedError(std::string err);
	~WrappedError() override = default;

	std::string Error() final;
	std::string const& Error() const final;
private:
	std::string error;
};

WrappedError::WrappedError(std::string err)
	: error {std::move(err)} {}

std::string WrappedError::Error() {
	return error;
}

std::string const& WrappedError::Error() const 
{
	return error;
}

}

error::ptr error::Wrap(ptr p, std::string err) 
{
	WrappedError::ptr rv = std::make_unique<WrappedError>(std::move(err));

	rv->underlying = std::move(p);
	return rv; 
}

error::ptr error::New(std::string err) {
	return Wrap(nullptr, std::move(err));
}
