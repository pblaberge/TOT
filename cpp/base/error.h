#pragma once

#include <memory>
#include <string>

class error
{
	public:
		using ptr = std::unique_ptr<error>;

		virtual ~error();

		static ptr New(std::string err);	
		static ptr Wrap(ptr p, std::string err);

		constexpr ptr const& Unwrap() const {return underlying;}

		virtual std::string Error() = 0;		
		virtual std::string const& Error() const = 0;		
	protected:
	   error();
	private:
	   ptr underlying;
};
