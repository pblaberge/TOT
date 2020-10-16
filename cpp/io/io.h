#pragma once

#include <memory>
#include <utility>

#include "absl/types/span.h"
#include "cpp/base/error.h"

namespace io
{

class Reader;
class Reader
{
public:
	using ptr = std::unique_ptr<Reader>;

	virtual ~Reader() = default;

	virtual std::pair<std::int32_t, error::ptr> Read(absl::Span<std::uint8_t> p) = 0;
};

class Writer;
class Writer {
public:
	using ptr = std::unique_ptr<Writer>;

	virtual ~Writer() = default;

	virtual std::pair<std::int32_t, error::ptr> Write(absl::Span<std::uint8_t> p) = 0;
};

class Closer;
class Closer {
public:
	using ptr = std::unique_ptr<Closer>;

	virtual ~Closer() = default;

	virtual error::ptr Close() = 0;
};

class ReadCloser;
class ReadCloser : public virtual Reader, public virtual Closer
{
	public:
	using ptr = std::unique_ptr<ReadCloser>;	

	~ReadCloser() override = default;
};

class WriteCloser;
class WriteCloser : public virtual Writer, public virtual Closer
{
	public:
	using ptr = std::unique_ptr<WriteCloser>;

	~WriteCloser() override = default;
};

class ReadWrite;
class ReadWrite : public virtual Reader, public virtual Writer
{
	public:
	using ptr = std::unique_ptr<ReadWrite>;

	~ReadWrite() override = default;
};

class ReadWriteCloser;
class ReadWriteCloser : public virtual Reader, public virtual Writer, public virtual Closer
{
	public:
		using ptr = std::unique_ptr<ReadWriteCloser>;

	~ReadWriteCloser() override = default;
};

}
