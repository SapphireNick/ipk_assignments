#include <iostream>
#include <cmath>

double phi{ (1 + std::sqrt(5)) / 2 }, psi{ 1 - phi };

unsigned long long fibonacci(int number)
{
	return (std::pow(phi, number) - std::pow(psi, number)) / std::sqrt(5);
}

int main(int argc, char** argv)
{
    int input;

    std::cout << "Please enter a number: " << std::flush;
    std::cin >> input;

	for (int i = 0; i < input; ++i) {
		std::cout << fibonacci(i) << '\n';
	}
	return 0;
}
