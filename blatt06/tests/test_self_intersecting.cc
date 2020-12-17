#include <iostream>
#include "../header/polygon.hh"

int main()
{
    std::vector<Point> coordinates;

    coordinates.push_back(Point(1, 1));
    coordinates.push_back(Point(-1, 1));
    coordinates.push_back(Point(1, -1));
    coordinates.push_back(Point(-1, -1));

    Polygon self_intersecting = Polygon(coordinates);

    std::cout << self_intersecting.volume() << std::endl;
    return 0;
}