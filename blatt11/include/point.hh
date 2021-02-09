#ifndef POINT_HH_Q6UFEYX7
#define POINT_HH_Q6UFEYX7

class Point {
	double _x, _y;

public:
	Point(double x = .0, double y = .0) : _x{x}, _y{y} {}

	double x() const { return _x; }
	double y() const { return _y; }

	Point operator+(const Point& p) const { return Point(_x + p.x(), _y + p.y()); }
	Point operator-(const Point& p) const { return Point(_x - p.x(), _y - p.y()); }

	Point& operator+=(const Point& p)
	{
		_x += p.x();
		_y += p.y();
		return *this;
	}
	Point& operator-=(const Point& p)
	{
		_x -= p.x();
		_y -= p.y();
		return *this;
	}

	Point operator*(const double& d) const { return Point(_x * d, _y * d); }
	friend Point operator*(const double& d, const Point& p) { return p * d; }

	Point& operator*=(const double& d)
	{
		_x *= d;
		_y *= d;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << '(' << p.x() << ", " << p.y() << ')'; }
};

#endif /* end of include guard: POINT_HH_Q6UFEYX7 */
