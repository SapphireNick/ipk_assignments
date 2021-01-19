// For debugging purposes
#include <iostream>
#include <string>
#include <cmath>
#include "IterationResult.hh"
#include "pgm.hh"
#include "canvas.hh"

IterationResult iterate (Point z, Point c, double threshold, int maxIt);
void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename);
void julia (Canvas& canvas, double threshold, int maxIt, std::string filename);

int main(int argc, char** argv)
{
    Canvas canv_mandl = Canvas(Point(-1, 0), 4, 3, 4000, 3000);
    Canvas canv_jul = Canvas(Point(-0.8, 0.156), 4, 3, 4000, 3000);

    // mandelbrot(canv_mandl, 3, 1000, "mandelbrot.pgm");
    julia(canv_jul, 3, 100, "julia.pgm");
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
    IterationResult iterRes = IterationResult(z, 0);
    Point tmp;
    double x, y;

    for (int i = 0; i < maxIt; i++)
    {
        x = iterRes.getPoint().x();
        y = iterRes.getPoint().y();
        if (x * x + y * y > threshold * threshold) 
        {
            return iterRes;
        }

        tmp = Point(x * x - y * y + c.x(),
                    2 * x * y + c.y());
        iterRes.getPoint() = tmp;
        iterRes.getPerfIter()++;
    }

    return iterRes;
}

void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename)
{
    int width = canvas.horPixels();
    int height = canvas.vertPixels();
    IterationResult res;

    std::cout << "Calculating mandelbrot..." << std::endl;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            res = iterate(Point(), canvas.coord(i, j),
                                            threshold, maxIt);

            if (res.getPerfIter() == maxIt)
            {
                canvas(i, j) = 0;
            }
            else
            {
                canvas(i, j) = std::log(res.getPerfIter()) * 100;
            }
        }
    }

    std::cout << "Writing mandelbrot..." << std::endl;
    canvas.write(filename);
}

void julia (Canvas& canvas, double threshold, int maxIt, std::string filename)
{
    int width = canvas.horPixels();
    int height = canvas.vertPixels();
    IterationResult res;

    std::cout << "Calculating julia..." << std::endl;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            res = iterate(canvas.coord(i, j), canvas.center(),
                                            threshold, maxIt);

            if (res.getPerfIter() == maxIt)
            {
                canvas(i, j) = 0;
            }
            else
            {
                canvas(i, j) = std::log(res.getPerfIter()) * 100;
            }
        }
    }

    std::cout << "Writing julia..." << std::endl;
    canvas.write(filename);

}