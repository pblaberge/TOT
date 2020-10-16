#include "cpp/io.hpp"

namespace io
{
    Reader::~Reader() = default;
    Writer::~Writer() = default;
    Closer::~Closer() = default;
    ReadCloser::~ReadCloser() = default;
    WriteCloser::~WriteCloser() = default;
    ReadWrite::~ReadWrite() = default;
    ReadWriteCloser::~ReadWriteCloser() = default;
}
