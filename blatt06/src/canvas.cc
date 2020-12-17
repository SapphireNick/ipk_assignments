#include "canvas.hh"
#include "pgm.hh"

//c
Canvas::Canvas(const Point& center, double width, double height, int horPixels, int vertPixels)
	: _center{center}, _width{width}, _height{height}, _horPixels{horPixels}, _vertPixels{vertPixels}, _pixels{horPixels, std::vector<int> (vertPixels, 0)}
{}

//d
int Canvas::brightness(int i, int j) const { return _pixels[i][j]; }

//e
void Canvas::setBrightness(int i, int j, int brightness) { _pixels[i][j] = brightness; }

//f
Point Canvas::coord(int i, int j) const
{
	return {_center.x + (i / (_horPixels - 1.0) - 0.5) * _width, _center.y + (j / (_vertPixels - 1.0) - 0.5) * _height};
}

//h
void Canvas::write(const std::string& filename) const { write_pgm(_pixels, filename); }
