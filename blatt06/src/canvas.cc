#include "../header/canvas.hh"

Canvas::Canvas(const Point& center, double width, double height,
                int horPixels, int vertPixels)
: _center(center), _width(width), _heigth(height),
    _horPixels(horPixels), _vertPixels(vertPixels),
    _pixels(horPixels, {{vertPixels}})
{};

int Canvas::brightness(int i, int j)
{
    return _pixels[i][j];
}

void Canvas::setBrightness(int i, int j, int brightness)
{
    _pixels[i][j] = brightness;
}

Point Canvas::coord(int i, int j) const
{
    return Point(i * (_width / _horPixels),
                 j * (_heigth / _vertPixels));
}