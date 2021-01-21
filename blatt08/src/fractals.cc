#include "canvas.hh"
#include "iterationresult.hh"
#include <cmath>
#include <string>
#include <iostream>

IterationResult iterate(Point z, Point c, double threshold, int maxIt)
{
	int i{};
	double t2{threshold * threshold};
	while (z.x * z.x + z.y * z.y <= t2 && i < maxIt) {
		z = (Point){z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y};
		++i;
	}
	return (IterationResult){z, i};
}

void mandelbrot(Canvas&& canvas, double threshold, int maxIt, std::string filename, bool smooth = false, bool range = false) 
{
	std::cout << "calculating mandelbrot" << '\n';
	double mul{256/std::log(maxIt)};
	for (int i = 0; i < canvas.horPixels(); ++i) {
		for (int j = 0; j < canvas.vertPixels(); ++j) {
			IterationResult itres = iterate(Point(), canvas.coord(i, j), threshold, maxIt);
			canvas(i, j) = itres.it == maxIt ? 0 : smooth
				? mul * std::log(itres.it - std::log2(std::log(std::sqrt(itres.p.x * itres.p.x + itres.p.y * itres.p.y))/std::log(threshold)))
				: mul * std::log(itres.it);
		}
	}
	std::cout << "writing mandelbrot" << '\n';
	if (range) canvas.adjustRange();
	canvas.write(filename);
}

void julia(Canvas&& canvas, double threshold, int maxIt, std::string filename, bool smooth = false) 
{
	std::cout << "calculating julia" << '\n';
	double mul{256/std::log(maxIt)};
	for (int i = 0; i < canvas.horPixels(); ++i) {
		for (int j = 0; j < canvas.vertPixels(); ++j) {
			IterationResult itres = iterate(canvas.coord(i, j), canvas.center(), threshold, maxIt);
			canvas(i, j) = itres.it == maxIt ? 0 : itres.it == 0 ? 255 : smooth
				? mul * std::log(itres.it - std::log2(std::log(std::sqrt(itres.p.x * itres.p.x + itres.p.y * itres.p.y))/std::log(threshold)))
				: mul * std::log(itres.it);
		}
	}
	std::cout << "writing julia" << '\n';
	canvas.write(filename);
}

int main(int argc, char** argv)
{
	mandelbrot(Canvas({-0.77568377, 0.13646737}, 0.002, 0.002, 8000, 8000), 2, 1000, "mandelbrot.pgm");
	julia(Canvas({-0.8, 0.156}, 1, 1, 8000, 8000), 2, 1000, "julia.pgm");
	mandelbrot(Canvas({-0.77568377, 0.13646737}, 0.002, 0.002, 8000, 8000), 2, 1000, "smandelbrot.pgm", true);
	julia(Canvas({-0.8, 0.156}, 1, 1, 8000, 8000), 2, 1000, "sjulia.pgm", true);
	mandelbrot(Canvas({-0.77568377, 0.13646737}, 0.002, 0.002, 8000, 8000), 2, 1000, "srmandelbrot.pgm", true, true);
	return 0;
}
