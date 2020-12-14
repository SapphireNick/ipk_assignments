#include "../header/polygon.hh"
#include <iostream>

Polygon::Polygon(const std::vector<Point>& corners)
: _corners(corners)
{};

Polygon::Polygon(const std::vector<double> x,
        const std::vector<double> y)
{
    int n = x.size();

    for (int i = 0; i < n; i++)
    {
        _corners.push_back(Point(x[i], y[i]));
    }
}

std::size_t Polygon::corners() const
{
    return Polygon::_corners.size();
}

const Point& Polygon::corner(std::size_t i) const
{
    return _corners[i];
}

double Polygon::volume() const
{
    double sum = 0;
    int n = _corners.size();

    if (n <= 2)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        sum += ((_corners[i].x() * _corners[i + 1].y()) - 
                (_corners[i + 1].x() * _corners[i].y()));
    }

    return 1/2 * sum;
}