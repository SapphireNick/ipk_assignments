#include <iostream>
#include "io.hh"
#include "statistics.hh"

int main(int argc, char** argv)
{
	auto v = uniform_distribution(0, 100, 0, 1);

	for (auto&& e : v) {
		std::cout << e << ' ';
	}
	double mean{statistics::mean(v)}, moment{statistics::moment(v, 2)}, stddev{statistics::standard_deviation(v)};
	std::cout << '\n';
	std::cout << "mean: " << mean << '\n';
	std::cout << "median: " << statistics::median(v) << '\n';
	std::cout << "2nd moment: " << moment << '\n';
	std::cout << "standard deviation: " << stddev << '\n';
	std::cout << (stddev*stddev == moment - mean * mean) << '\n';
	
	return 0;
}
