#include "canvas.hh"
#include "iterationresult.hh"
#include <cmath>
#include <string>
#include <iostream>

IterationResult iterate(Point z, Point c, double threshold, int maxIt)
{
	int i{};
	double t2{threshold * threshold};
	while (i < maxIt && z.x * z.x + z.y * z.y < t2) {
		z = (Point){z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y};
		++i;
	}
	return (IterationResult){c, i};
}

void mandelbrot(Canvas&& canvas, double threshold, int maxIt, std::string filename) 
{
	for (int i = 0; i < canvas.horPixels(); ++i) {
		for (int j = 0; j < canvas.vertPixels(); ++j) {
			IterationResult itres = iterate(Point(), canvas.coord(i, j), threshold, maxIt);
			canvas(i, j) = itres.it == maxIt ? 0 : 36 * std::log(itres.it);
		}
	}
	std::cout << "writing file:" << '\n';
	canvas.write(filename);
}

int main(int argc, char** argv)
{
	mandelbrot(Canvas({-0.77568377, 0.13646737}, 0.002, 0.002, 8000, 8000), 3, 1000, "mandelbrot.pgm");
	return 0;
}
