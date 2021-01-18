// For debugging purposes
#include <iostream>
#include <string>
#include <cmath>
#include "IterationResult.hh"
#include "pgm.hh"
#include "../include/canvas.hh"

IterationResult iterate (Point z, Point c, double threshold, int maxIt);
void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename);

int main(int argc, char** argv)
{
    Canvas canv = Canvas(Point(-1, 0), 4, 3, 50, 50);
    mandelbrot(canv, 3, 100, "mandelbrot.pgm");
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
    IterationResult iterRes = IterationResult(z, 0);
    Point tmp;
    double x, y;
    static int count = 0;

    for (int i = 0; i < maxIt; i++)
    {
        x = iterRes.getPoint().x();
        y = iterRes.getPoint().y();
        if (x * x + y * y > threshold * threshold) 
        {
            // count++;
            // std::cout << count << "   ";
            return iterRes;
        }

        tmp = Point(x * x - y * y + c.x(),
                    2 * x * y + c.y());
        iterRes.getPoint() = tmp;
        iterRes.getPerfIter()++;
    }

    return iterRes;
}

// IterationResult iterate(Point z, Point c, double threshold, int maxIt)
// {
//     static int count = 0;
// 	int i{};
// 	double t2{threshold * threshold};
// 	while (z.x() * z.x() + z.y() * z.y() <= t2 && i < maxIt) {
// 		z = (Point){z.x() * z.x() - z.y() * z.y() + c.x(), 2 * z.x() * z.y() + c.y()};
// 		++i;
// 	}
//     if (i != maxIt)
//         std::cout << ++count << " ";
    
// 	return (IterationResult){z, i};
// }

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

            // std::cout << res.getPerfIter() << "  ";

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