#include <iostream>
#include "io.hh"
#include "statistics.hh"

int main(int argc, char** argv)
{
	auto v = read_vector();

	for (auto&& e : v) {
		std::cout << e << ' ';
	}
	double m{mean(v)}, mom{moment(v, 2)}, stddev{standard_deviation(v)};
	std::cout << '\n';
	std::cout << "mean: " << m << '\n';
	std::cout << "median: " << median(v) << '\n';
	std::cout << "2nd moment: " << mom << '\n';
	std::cout << "standard deviation: " << stddev << '\n';
	std::cout << (stddev * stddev == mom - m * m) << '\n';
	
	return 0;
}
