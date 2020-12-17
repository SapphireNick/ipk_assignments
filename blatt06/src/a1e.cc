#include <iostream>

#include "polygon.hh"

//e
int main(int argc, char** argv)
{
	std::cout << Polygon({{-1, 1}, {1, 1}, {0, 0}}).volume() << '\n';
	std::cout << Polygon({{0, 0}, {-1, -1}, {1, -1}}).volume() << '\n';
	std::cout << Polygon({{-1, 1}, {1, 1}, {-1, -1}, {1, -1}}).volume() << '\n';
	return 0;
}
