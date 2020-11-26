#include <iostream>
#include <limits>
#include "power.h"

int main(int argc, char** argv)
{
	int q{};
	unsigned n{};
	bool qb{}, nb{};

	std::cout << "input q: " << std::flush;
	while (!(std::cin >> q)) {
		std::cout << "error: input not compatible with type int, try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "q = " << q << '\n';
	
	std::cout << "input n: " << std::flush;
	while (!(std::cin >> n)) {
		std::cout << "error: input not compatible with type int, try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "n = " << n << '\n';

	std::cout << power::iterative(q, n) << '\n';
	std::cout << power::recursive(q, n) << '\n';

	return 0;
}
