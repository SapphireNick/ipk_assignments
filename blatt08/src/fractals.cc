// For debugging purposes
#include <iostream>
#include <string>
#include <cmath>
#include "IterationResult.hh"
#include "pgm.hh"
#include "canvas.hh"

IterationResult iterate (Point z, Point c, double threshold, int maxIt);
void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth = false);
void julia (Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth = false);

int main(int argc, char** argv)
{
    Canvas canv_mandl = Canvas(Point(-1, 0), 4, 3, 4000, 3000);
    Canvas canv_jul_1 = Canvas(Point(-0.8, 0.156), 4, 3, 4000, 3000);
    Canvas canv_jul_2 = Canvas(Point(0.1, 0.64), 3, 4, 3000, 4000);

    // mandelbrot(canv_mandl, 3, 1000, "mandelbrot.pgm");
    // mandelbrot(canv_mandl, 3, 1000, "mandelbrot_smooth.pgm", true);
    // julia(canv_jul_1, 5, 1000, "julia.pgm");
    // julia(canv_jul_1, 5, 1000, "julia_smooth.pgm", true);
    julia(canv_jul_2, 5, 1000, "julia2_smooth.pgm", true);
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
    IterationResult iterRes = IterationResult(z, 1);
    Point tmp;
    double x, y;

    for (int i = 0; i < maxIt - 1; i++)
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

void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth)
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
            else if (smooth)
            {
                canvas(i, j) = std::log(res.getPerfIter() -
                                std::log2(std::log((std::sqrt(std::pow(res.getPoint().x(), 2) +
                                                        std::pow(res.getPoint().y(), 2)))) /
                                            std::log(threshold))) * 100;
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

void julia (Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth)
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
            else if (smooth)
            {
                canvas(i, j) = std::log(res.getPerfIter() -
                                std::log2(std::log((std::sqrt(std::pow(res.getPoint().x(), 2) +
                                                        std::pow(res.getPoint().y(), 2)))) /
                                            std::log(threshold))) * 100;
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