#ifndef CANVAS_HH_PCXK8D7T
#define CANVAS_HH_PCXK8D7T

#include "point.hh"
#include <vector>
#include <string>

class Canvas {
	const Point _center;
	const double _width, _height;
	const unsigned int _horPixels, _vertPixels;
	std::vector<std::vector<int>> _pixels;
	int _min{-1};

public:
	Canvas(const Point& center = {-1, 0}, double width = 12, double height = 9, unsigned int horPixels = 4000, unsigned int vertPixels = 3000);

	Point center() const;
	double width() const;
	double height() const;
	unsigned int horPixels() const;
	unsigned int vertPixels() const;

	int min();
	void adjustRange();

	int operator()(int i, int j) const;
	int& operator()(int i, int j);
	Point coord(int i, int j) const;
	void write(const std::string& filename) const;
};

#endif /* end of include guard: CANVAS_HH_PCXK8D7T */
