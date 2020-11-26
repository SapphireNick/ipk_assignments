#include <iostream>
#include <iomanip>

#include "power.h"

//a, b
/**
* @brief: calculates the nth root iteratively
*
* @param: double q
*       : int n
*       : int steps
*
* @return: double
*/
double root_iterative(double q, int n, int steps)
{
	if (n) {		
		double a{ q };
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
*       : int n
*       : int steps
*
* @return: void
*/
void test_root(double q, double n, int steps)
{	
	double approx = root_iterative(q, n, steps);
	double pot = power::recursive(approx, n);
	std::cout << "q ist: " << q << "\n" << "n ist: " << n << "\n"
	  << "Anzahl der steps: " << steps << "\n" << "Differenz der Näherung: " 
	  << q - pot << "\n";
}

int main(int argc, char** argv)
{
	double q; 
	int n, steps;
	
	std::cout << "Aus welcher Zahl möchtest du die Wurzel ziehen?: " << std::flush;
	std::cin >> q;

	std::cout << "Die wievielte Wurzel?: " << std::flush;
	std::cin >> n;
	
	std::cout << "Wie viele steps?: " << std::flush;
	std::cin >> steps;
	
	if (q < 0 or n < 0 or steps <= 0)
	{
		std::cout << "Ungültige Eingabe." << std::endl;
		return 1;
	}
	
	std::cout <<  "Die Näherung der Wurzel ist: " << 
	  root_iterative(q, n, steps) << "\n" << std::endl;
	test_root(q, n, steps);
	return 0;
}

