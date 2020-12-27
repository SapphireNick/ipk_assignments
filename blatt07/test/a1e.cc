#include <stdexcept>
#include <cmath>

#include "point.hh"

template <typename Coord, int dim>
void check_norm(const Point<Coord, dim>& p)
{
	double s{};

	for (int i = 0; i < dim; ++i) {
		s += std::pow(p[i], 2);
	}
	if (std::sqrt(s) != p.norm()) throw std::runtime_error("norm mismatch");
}

int main(int argc, char** argv)
{
	Point<int, 1> p0{}, p1{{1}};
	Point<int, 3> p2{}, p3{{-1, 0, 1}}, p4{{1, 2, 3}};
	Point<double, 1> p5{}, p6{{1}};
	Point<double, 3> p7{}, p8{{-1, 0, 1}}, p9{{1.1, 2.5, 3.9}};

	check_norm(p0);
	check_norm(p1);
	check_norm(p2);
	check_norm(p3);
	check_norm(p4);
	check_norm(p5);
	check_norm(p6);
	check_norm(p7);
	check_norm(p8);
	check_norm(p9);

	return 0;
}
