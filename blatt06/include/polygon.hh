#ifndef POLYGON_HH_L64YDMSA
#define POLYGON_HH_L64YDMSA

#include "point.hh"
#include <vector>

class Polygon {
	std::vector<Point> _corners;

public:
	Polygon(const std::vector<Point>& corners);
	Polygon(const std::vector<double>& x, const std::vector<double>& y);
	std::size_t corners() const;
	const Point& corner(std::size_t i) const;
	double volume() const;
};

#endif /* end of include guard: POLYGON_HH_L64YDMSA */
