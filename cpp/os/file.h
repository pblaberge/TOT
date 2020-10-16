#pragma once

#include <memory>
#include <string>
#include <tuple>

#include "cpp/io/io.h"

namespace os {

class File : public virtual io::Reader,
             public virtual io::Writer,
             public virtual io::Closer,
             public virtual io::ReadCloser,
             public virtual io::WriteCloser,
             public virtual io::ReadWriteCloser {
 public:
  using ptr = std::unique_ptr<File>;

  ~File() override = default;

  virtual int Fd() const = 0;
};

extern File::ptr Stdin;
extern File::ptr Stdout;
extern File::ptr Stderr;
extern File::ptr DevNull;

File::ptr NewFile(int fd, std::string name);
File::ptr OpenFile(std::string name, int flag, int filemode);
std::tuple<File::ptr, File::ptr, error::ptr> Pipe();

}  // namespace os
