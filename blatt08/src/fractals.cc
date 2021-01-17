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

void mandelbrot(Canvas&& canvas, double threshold, int maxIt, std::string filename, bool smooth = false) 
{
	std::cout << "calculating mandelbrot" << '\n';
	for (int i = 0; i < canvas.horPixels(); ++i) {
		for (int j = 0; j < canvas.vertPixels(); ++j) {
			IterationResult itres = iterate(Point(), canvas.coord(i, j), threshold, maxIt);
			canvas(i, j) = itres.it == maxIt ? 0 : smooth ? 
				36 * std::log(itres.it - std::log2(std::log(std::sqrt(itres.p.x * itres.p.x + itres.p.y * itres.p.y))/std::log(threshold))): 
				36 * std::log(itres.it);
		}
	}
	std::cout << "writing mandelbrot" << '\n';
	canvas.write(filename);
}

void julia(Canvas&& canvas, double threshold, int maxIt, std::string filename, bool smooth = false) 
{
	std::cout << "calculating julia" << '\n';
	for (int i = 0; i < canvas.horPixels(); ++i) {
		for (int j = 0; j < canvas.vertPixels(); ++j) {
			IterationResult itres = iterate(canvas.coord(i, j), canvas.center(), threshold, maxIt);
			canvas(i, j) = itres.it == maxIt ? 0 : smooth ? 
				36 * std::log(itres.it - std::log2(std::log(std::sqrt(itres.p.x * itres.p.x + itres.p.y * itres.p.y))/std::log(threshold))): 
				36 * std::log(itres.it);
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
	return 0;
}
