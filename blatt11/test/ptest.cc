#include "sdlwrapper.hh"
#include "point.hh"

int main(int argc, char** argv)
{
	Point a{1, 2}, b{3, 4};
	Point a2{1, 2}, b2{3, 4};

	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << a + b << '\n';
	std::cout << a - b << '\n';
	std::cout << (a2 += b2) << '\n';
	std::cout << a2 << '\n';
	std::cout << (a2 -= b2) << '\n';
	std::cout << a2 << '\n';
	std::cout << a * 4 << '\n';
	std::cout << 4 * a << '\n';
	std::cout << (a *= 4) << '\n';
	std::cout << a << '\n';

	return 0;
}
