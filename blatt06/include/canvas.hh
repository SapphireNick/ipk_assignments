#ifndef CANVAS_HH
#define CANVAS_HH

#include <vector>
#include <string>
#include "point.hh"

class Canvas
{
private:
    const int _horPixels;
    const int _vertPixels;
    const double _heigth;
    const double _width;
    const Point _center;
    std::vector<std::vector<int>> _pixels;

public:
    Canvas(const Point& center, double width, double height,
            int horPixels, int vertPixels);
    int brightness(int i, int j);
    void setBrightness(int i, int j, int brightness);
    Point coord(int i , int j) const;
    void write(const std::string& filename);
};

#endif // CANVAS_HH