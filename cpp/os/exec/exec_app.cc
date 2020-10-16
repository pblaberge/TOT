#include "cpp/os/exec/exec.h"

#include <iostream>

int main()
{
	auto [out, err] = os::exec::Command("/bin/date")->Output();

	for (std::uint8_t b : out) {
		char c = b;

		std::cout << c;
	}

	std::cout << std::endl;
}
