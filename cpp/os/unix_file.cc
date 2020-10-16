#include "cpp/os/file.h"

#include <fcntl.h>              
#include <unistd.h>

namespace os
{

File::ptr Stdin = NewFile(0, "/dev/stdin");
File::ptr Stdout = NewFile(1, "/dev/stdout");
File::ptr Stderr = NewFile(2, "/dev/stderr");
File::ptr DevNull = OpenFile("/dev/null", O_RDWR, 0);

class UnixFile final : public File
{
    public:
	UnixFile(int fd, std::string name);

	UnixFile(UnixFile const& other) = delete;
	UnixFile& operator=(UnixFile const& other) = delete;

	~UnixFile() final;

	std::pair<std::int32_t, error::ptr> 
		Read(absl::Span<std::uint8_t> p) final;

	std::pair<std::int32_t, error::ptr> 
		Write(absl::Span<std::uint8_t> p) final;

	error::ptr Close() final;

	int Fd() const final;

   private:
	int fd;
	std::string name;
};

File::ptr NewFile(int fd, std::string name)
{
	return std::make_unique<UnixFile>(fd, std::move(name));
}

int UnixFile::Fd() const
{
return fd;
}

File::ptr OpenFile(std::string name, int flags, int perm)
{
	int fd = open(name.c_str(), flags);
	if (fd <0) {
		return nullptr;
	}

	return NewFile(fd, std::move(name));
}

UnixFile::UnixFile(int fd_, std::string name_) : fd{fd_}, name{std::move(name_)} {}

UnixFile::~UnixFile()
{
    Close();
}

std::pair<std::int32_t, error::ptr> 
		UnixFile::Read(absl::Span<std::uint8_t> p)
{
	//TODO make errors
	
	int n = read(fd, p.data(), p.size());
        if (n < 0) {
		return {0, nullptr};
	}	

	return {n, nullptr};
}

std::pair<std::int32_t, error::ptr> 
		UnixFile::Write(absl::Span<std::uint8_t> p)
{
	// TODO make errors
	
	int n = write(fd, p.data(), p.size());
	if (n < 0)
	{
		return {0, nullptr};
	}

	return {n, nullptr};
}

error::ptr UnixFile::Close()
{
	if (fd >= 0)
	{	
		if (int rv = close(fd); rv != 0) {
			return nullptr; // TODO make an error	
		}
		fd = -1;
	}
	return nullptr;
}

std::tuple<File::ptr, File::ptr, error::ptr> Pipe()
{
	std::array<int, 2> pipe_fd;
	pipe2(pipe_fd.data(), O_CLOEXEC);
	//TODO make error;
	return {
	    NewFile(pipe_fd[0], "|0"),
	    NewFile(pipe_fd[1], "|1"),
	    nullptr
	};
}

}
