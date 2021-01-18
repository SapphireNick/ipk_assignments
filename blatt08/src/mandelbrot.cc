// For debugging purposes
// #include <iostream>
#include <string>
#include <cmath>
#include "IterationResult.hh"
#include "pgm.hh"
#include "../include/canvas.hh"

IterationResult iterate (Point z, Point c, double threshold, int maxIt);
void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename);

int main(int argc, char** argv)
{
    Canvas canv = Canvas(Point(-1, 0), 20, 15, 4000, 3000);
    mandelbrot(canv, 1000, 1000, "mandelbrot.pgm");
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
    IterationResult iterRes = IterationResult(z, 0);
    Point tmp;
    double distanceToOrigin = std::sqrt( std::pow(z.x(), 2) + std::pow(z.y(), 2));

    for (int i = 0; i < maxIt; i++)
    {
        if (distanceToOrigin > threshold) return iterRes;

        tmp = Point(std::pow(iterRes.getPoint().x(), 2) + c.x(),
                    std::pow(iterRes.getPoint().y(), 2) + c.y());
        iterRes.getPoint() = tmp;
        iterRes.getPerfIter()++;
        distanceToOrigin = std::sqrt( std::pow(iterRes.getPoint().x(), 2)
                                    + std::pow(iterRes.getPoint().y(), 2));
    }

    return iterRes;
}

void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename)
{
    int width = canvas.horPixels();
    int height = canvas.vertPixels();
    IterationResult res;

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

    canvas.write(filename);
}