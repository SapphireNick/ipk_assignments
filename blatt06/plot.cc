#include <cmath>
#include <iostream>
#include "header/canvas.hh"
#include "header/pgm.hh"

int grayscale_function(const Point& coords);

int main()
{
    Point center = Point(0, 0);
    double width = 4;
    double height = 3;
    int horPixels = 4000;
    int vertPixels = 3000;
    std::vector<std::vector<int>> points(horPixels, {{vertPixels}});
    Canvas plot_canv = Canvas(center, width, height, horPixels, vertPixels);

    for(int i = 0; i < horPixels; i++)
    {
        for(int j = 0; j < vertPixels; j++)
        {
            plot_canv.setBrightness(i, j, grayscale_function(plot_canv.coord(i, j)));
        }
    }
    plot_canv.write("plot.pgm");
}

int grayscale_function(const Point& coords)
{
    return std::max(0,(int) std::round(100 * (std::sin(1/coords.x()) * std::sin(1/coords.y()) + 1)));
}
