#include <iostream>
#include <iomanip>

#include "power.h"

//a, b
/**
* @brief: calculates the nth root iteratively
*
* @param: double q
*       : unsigned n
*       : unsigned steps
*
* @return: double
*/
double root_iterative(double q, unsigned n, unsigned steps)
{
	if (n) {		
		double a{ 1 };
		if (n==1) return q;
		for (int i = 0; i < steps; ++i) {
			a += (q/power::recursive(a, n-1)-a)/n;
		}
		return a;
	}
	std::cout << "n = 0" << '\n';
	return 0;
}

//c
/**
* @brief: tests the accuracy of the approximation of the root given by root_iterative 
*
* @param: double q
*       : unsigned n
*       : unsigned steps
*
* @return: void
*/
void test_root(double q, unsigned n, unsigned steps)
{
	std::cout << std::left;
	std::cout << "q = " << std::setw(20) << q << ", ";
	std::cout << "n = " << std::setw(20) << n << ", ";
	std::cout << "steps = " << std::setw(20) << steps << ", ";
	std::cout << "q - an = " << q - power::recursive(root_iterative(q, n, steps), n) << '\n';
		
}

int main(int argc, char** argv)
{
	test_root(1111111111, 1, 1000);
	test_root(2222222222, 2, 1000);
	test_root(3333333333, 3, 1000);
	test_root(4444444444, 4, 1000);
	test_root(5555555555, 5, 1000);
	test_root(6666666666, 6, 1000);
	test_root(7777777777, 7, 1000);
	test_root(8888888888, 8, 1000);
	test_root(9999999999, 9, 1000);
	test_root(1234567890, 1, 1000);
	test_root(1234567890, 2, 1000);
	std::cout << root_iterative(1e10, 9, 1000) << '\n';

	return 0;
}

