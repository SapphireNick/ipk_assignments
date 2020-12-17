#include <cmath>
#include <stdexcept>

#include "polygon.hh"

//d
int main(int argc, char** argv)
{
	double pi = M_PI;
	if (Polygon({}).volume() != 0) throw std::runtime_error("Area of empty polygon not 0");
	for (int n = 1; n < 13; ++n) {
		std::vector<Point> corners;
		for (int i = 0; i < n; ++i) {
			corners.push_back({std::cos(2 * pi * i / n), std::sin(2 * pi * i / n)});
		}
		if (std::abs((n * std::sin(2 * pi / n) / 2) - Polygon(corners).volume()) > 1e-15) throw std::runtime_error("Area doesn't match");
	}
	return 0;
}
