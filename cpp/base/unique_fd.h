#pragma once

namespace base
{

class UniqueFD
{
   public:
	constexpr UniqueFD(int fd);

	UniqueFD(UniqueFD const& other) = delete;
	UniqueFD& operator=(UniqueFD const& other) = delete;

	~UniqueFD();

	constexpr int GetFD() const;

   private:
	int fd_;
};

constexpr UniqueFD::UniqueFD(int fd) : fd_{fd} {}

int UniqueFD::GetFD() const
{
    return fd_;
}

}
