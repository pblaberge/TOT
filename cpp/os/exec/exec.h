#pragma once

#include <memory>
#include <string>
#include <vector>
#include <utility>

#include "absl/types/optional.h"
#include "cpp/base/error.h"
#include "cpp/io/io.h"
#include "cpp/os/file.h"

namespace os
{
namespace exec
{

class Cmd
{
public:
	using ptr = std::unique_ptr<Cmd>;

	Cmd();

	virtual ~Cmd();

	virtual error::ptr Start() = 0;
	virtual error::ptr Wait() = 0;
	virtual error::ptr Run() = 0;

	virtual std::pair<std::vector<std::uint8_t>, error::ptr> Output() = 0;
	virtual std::pair<std::vector<std::uint8_t>, error::ptr> CombinedOutput() = 0;

	virtual std::pair<io::ReadCloser::ptr, error::ptr> StderrPipe() = 0;
	virtual std::pair<io::WriteCloser::ptr, error::ptr> StdinPipe() = 0;
	virtual std::pair<io::ReadCloser::ptr, error::ptr> StdoutPipe() = 0;

	std::string path;

	std::vector<std::string> args;
	
	absl::optional<std::vector<std::string>> env;

	std::string dir;

	File::ptr stdin;
	File::ptr stdout;
	File::ptr stderr;

	std::vector<File::ptr> extra_files;

	//TODO add process obj;
};

Cmd::ptr Command(std::string name, std::vector<std::string> args = {});

}
}
