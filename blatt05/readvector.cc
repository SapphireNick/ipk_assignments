#include "statistics.hh" 
#include "io.hh" 
#include <iostream>
#include <vector>
#include <cmath>

int main(int args, char** argv)
{
		std::vector<double> v = read_vector();
		std::cout << "mean: " << mean(v) << "\n";
		std::cout << "median: " << median(v) << "\n";
		std::cout << "moment: " << moment(v, 2) << "\n";
		std::cout << "standard_deviation: " << standard_deviation(v) << "\n";
		return 0;
}
