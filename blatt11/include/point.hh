#ifndef POINT_HH
#define POINT_HH

#include <iostream>

class Point {
 public:
  // default constructor
  Point() : _x(0.0), _y(0.0) {}

  // constructor für übergebene Koordinaten
  Point(double x, double y) : _x(x), _y(y) {}

  // Accessors

  double x() const { return _x; }

  double y() const { return _y; }

  Point operator+(Point b) const
  {
    return Point(_x + b.x(), _y + b.y());
  }

  Point operator-(Point b) const
  {
    return Point(_x - b.x(), _y - b.y());
  }

  Point& operator+=(Point b)
  {
    _x += b.x();
    _y += b.y();
    return *this;
  }

  Point& operator-=(Point b)
  {
    _x -= b.x();
    _y -= b.y();
    return *this;
  }

  Point& operator*=(double d)
  {
    _x *= d;
    _y *= d;
    return *this;
  }

  Point operator*(double d) const
  {
    return Point(_x * d, _y * d);
  }

  friend Point operator*(double d, Point a)
  {
    return a * d;
  }

  friend std::ostream& operator<<(
    std::ostream& os, const Point& a)
  {
    os << "(" << a.x() << ", " << a.y() << ")";
    return os;
  }

private:
  double _x;
  double _y;
};

#endif  // POINT_HH
