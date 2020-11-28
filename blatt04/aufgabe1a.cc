#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<double> v1;
	std::vector<double> v2(10);
	std::vector<double> v3 {0, .1, 1.0, 2.2};

	std::cout << "v1:" << '\n';
	for (auto&& i : v1) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
	
	std::cout << "v2:" << '\n';
	for (auto&& i : v2) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::cout << "v3:" << '\n';
	for (auto&& i : v3) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	return 0;
}
