#ifndef BODY_HH_2I45S8Q7
#define BODY_HH_2I45S8Q7

#include "point.hh"
#include <array>

class Body {
	Point _x, _v, _a{};
	double _m;
	std::array<int, 3> _c;

public:
	Body(Point x = Point(), Point v = Point(), double m = 1, std::array<int, 3> c = std::array<int, 3>())
		: _x{x}, _v{v}, _m{m}, _c{c} {}

	Point& x() { return _x; }
	Point& v() { return _v; }
	Point& a() { return _a; }
	double& m() { return _m; }
	Point x() const { return _x; }
	Point v() const { return _v; }
	Point a() const { return _a; }
	double m() const  { return _m; }
	std::array<int, 3>& c() { return _c; }
};

#endif /* end of include guard: BODY_HH_2I45S8Q7 */
