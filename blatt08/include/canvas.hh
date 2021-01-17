#ifndef CANVAS_HH_PCXK8D7T
#define CANVAS_HH_PCXK8D7T

#include "point.hh"
#include <vector>
#include <string>

class Canvas {
	const Point _center;
	const double _width, _height;
	const int _horPixels, _vertPixels;
	std::vector<std::vector<int>> _pixels;

public:
	Canvas(const Point& center = {-1, 0}, double width = 12, double height = 9, int horPixels = 4000, int vertPixels = 3000);

	Point center() const;
	double width() const;
	double height() const;
	int horPixels() const;
	int vertPixels() const;

	int operator()(int i, int j) const;
	int& operator()(int i, int j);
	Point coord(int i, int j) const;
	void write(const std::string& filename) const;
};

#endif /* end of include guard: CANVAS_HH_PCXK8D7T */
