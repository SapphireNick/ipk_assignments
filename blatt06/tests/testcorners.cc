#include <stdexcept>
#include <vector>

#include "canvas.hh"

//d
int main(int argc, char** argv)
{
	Canvas c;
	if (c.coord(0, 0).x != -8 || c.coord(0, 0).y != -4.5) throw std::runtime_error("bottom left");
	if (c.coord(2559, 0).x != 8 || c.coord(2559, 0).y != -4.5) throw std::runtime_error("bottom right");
	if (c.coord(0, 1439).x != -8 || c.coord(0, 1439).y != 4.5) throw std::runtime_error("top left");
	if (c.coord(2559, 1439).x != 8 || c.coord(2559, 1439).y != 4.5) throw std::runtime_error("top right");

	Canvas c1{{0.99, 0.99}, 15.9, 8.9, 2559, 1439};
	if (c1.coord(0, 0).x != 0.99 - 7.95 || c1.coord(0, 0).y != 0.99 - 4.45) throw std::runtime_error("bottom left");
	if (c1.coord(2558, 0).x != 0.99 + 7.95 || c1.coord(2558, 0).y != 0.99 - 4.45) throw std::runtime_error("bottom right");
	if (c1.coord(0, 1438).x != 0.99 - 7.95 || c1.coord(0, 1438).y != 0.99 + 4.45) throw std::runtime_error("top left");
	if (c1.coord(2558, 1438).x != 0.99 + 7.95 || c1.coord(2558, 1438).y != 0.99 + 4.45) throw std::runtime_error("top right");

	return 0;
}
