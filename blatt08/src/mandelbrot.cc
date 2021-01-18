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
    Canvas canv = Canvas(Point(-1, 0), 4, 3, 1000, 500);
    mandelbrot(canv, 2, 1000, "mandelbrot.pgm");
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
    IterationResult iterRes = IterationResult(z, 0);
    Point tmp;
    int x, y;
    double distanceToOrigin_sq = std::pow(z.x(), 2) + std::pow(z.y(), 2);

    for (int i = 0; i < maxIt; i++)
    {
        x = iterRes.getPoint().x();
        y = iterRes.getPoint().y();
        if (distanceToOrigin_sq > threshold * threshold) return iterRes;

        tmp = Point(x * x - y * y + c.x(),
                    2 * x * y + c.y());
        iterRes.getPoint() = tmp;
        iterRes.getPerfIter()++;
        distanceToOrigin_sq = x * x + y * y;
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

    canvas.write(filename);
}