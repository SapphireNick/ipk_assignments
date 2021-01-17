#include "canvas.hh"
#include "pgm.hh"

//c
Canvas::Canvas(const Point& center, double width, double height, int horPixels, int vertPixels)
	: _center{center}, _width{width}, _height{height}, _horPixels{horPixels}, _vertPixels{vertPixels}, _pixels{horPixels, std::vector<int>(vertPixels, 0)}
{}

Point Canvas::center() const { return _center; }

double Canvas::width() const { return _width; }

double Canvas::height() const { return _height; }

int Canvas::horPixels() const { return _horPixels; }

int Canvas::vertPixels() const {return _vertPixels; }

int Canvas::operator()(int i, int j) const { return _pixels[i][j]; }

int& Canvas::operator()(int i, int j) { return _pixels[i][j]; }

Point Canvas::coord(int i, int j) const
{
	return {_center.x + (i / (_horPixels - 1.0) - 0.5) * _width, _center.y + (j / (_vertPixels - 1.0) - 0.5) * _height};
}

void Canvas::write(const std::string& filename) const { write_pgm(_pixels, filename); }
