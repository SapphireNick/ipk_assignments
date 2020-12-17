#include "point.hh"

Point::Point()
{};

Point::Point(double x, double y)
: _x(x), _y(y)
{};

double Point::x() const
{
    return Point::_x;
}

double Point::y() const
{
    return Point::_y;
}
