#ifndef POINT_HH_AP0VP2HT
#define POINT_HH_AP0VP2HT

#include <array>
#include <cmath>

template <typename Coord, int dim>
class Point {
	std::array<Coord, dim> _coords;

public:
	static const int dimension = dim;

	Point(const std::array<Coord, dim>& coords = std::array<Coord, dim>{}) : _coords{coords} {}

	double norm() const
	{
		double s{};

		for (auto&& e : _coords) {
			s += std::pow(e, 2);
		}
		return std::sqrt(s);
	}

	Coord& operator[](int i) { return _coords[i]; }

	const Coord& operator[](int i) const { return _coords[i]; }
};

#endif /* end of include guard: POINT_HH_AP0VP2HT */
