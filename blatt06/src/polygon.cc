#include "polygon.hh"

//b
Polygon::Polygon(const std::vector<Point>& corners) : _corners{corners} {}

Polygon::Polygon(const std::vector<double>& x, const std::vector<double>& y)
{
	for (int i = 0; i < x.size(); ++i) {
		_corners.push_back({x[i], y[i]});
	}
}

std::size_t Polygon::corners() const { return _corners.size(); }

const Point& Polygon::corner(std::size_t i) const { return _corners[i]; }

//c
double Polygon::volume() const
{
	if (_corners.size() < 3) return 0;

	double a{};
	for (int i = 0; i < _corners.size() - 1; ++i) {
		a += _corners[i].x * _corners[i + 1].y - _corners[i + 1].x * _corners[i].y;
	}
	a += _corners[_corners.size() - 1].x * _corners[0].y - _corners[0].x * _corners[_corners.size() - 1].y;
	return a / 2;
}
