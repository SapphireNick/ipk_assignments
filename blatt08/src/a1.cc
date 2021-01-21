#include <iostream>
#include <cmath>
#include <string>
#include "../include/canvas.hh"
#include "../include/iterationresult.hh"

double distance(Point p)
{
	return std::sqrt(std::pow(p.x(),2) + std::pow(p.y(),2));
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
	int i{};
	while ((distance(z) <= threshold) and (i <= maxIt)){
		z = (Point) {(std::pow(z.x(),2) - std::pow(z.y(),2) + c.x()), 2 * z.x() * z.y() + c.y()};
		++i;
	}
	IterationResult res{z, i};
	return res; 
}

void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename)
{
	for(int i = 0; i < canvas.horPixels(); ++i){
		for (int j = 0; j < canvas.vertPixels(); ++j){
			IterationResult res = iterate(Point(), canvas.coord(i, j), threshold, maxIt);
			if (res.getnumIt() < maxIt){
				canvas(i, j) = 0;
			}
			else{
				canvas(i, j) = std::log(res.getnumIt()) * 100;
			}
		}
	}
	canvas.write(filename);
}

void julia (Point c , Canvas& canvas, double threshold, int maxIt, std::string filename)
{
	for(int i = 0; i < canvas.horPixels(); ++i){
		for (int j = 0; j < canvas.vertPixels(); ++j){
			IterationResult res = iterate(canvas.coord(i, j), Point(-0.8, 0.156), threshold, maxIt);
			if (res.getnumIt() < maxIt){
				canvas(i, j) = 0;
			}
			else{
				canvas(i, j) = std::log(res.getnumIt()) * 100;
			}
		}
	}
	canvas.write(filename);
}

int main(int argc, char** argv)
{
	Canvas canvas_mndl(Point(-1,0), 4, 3, 4000, 3000);
	Canvas canvas_julia(Point(-0.8,0.156), 4, 3, 4000, 3000);
	mandelbrot(canvas_mndl, 1000, 1000, "plot_mndl.pgm");
	julia(Point(-0.8, 0.156),canvas_julia, 1000, 1000, "plot_julia.pgm");
	return 0;
}


	

