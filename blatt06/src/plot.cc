#include "canvas.hh"
#include <cmath>

//h
int f(const Point& p) { return std::max(0, (int) std::round(100 * (std::sin(1 / p.x) * std::sin(1 / p.y) + 1))); }

int main(int argc, char** argv)
{
	Canvas c{{0, 0}, 4, 3, 4000, 3000};

	for (int i = 0; i < 4000; ++i) {
		for (int j = 0; j < 3000; ++j) {
			c.setBrightness(i, j, f(c.coord(i, j)));
		}
	}
	c.write("plot.pgm");

	return 0;
}
