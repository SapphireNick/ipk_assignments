#ifndef CANVAS_HH_PCXK8D7T
#define CANVAS_HH_PCXK8D7T

#include "point.hh"
#include <vector>
#include <string>

//ab
class Canvas {
	const Point _center;
	const double _width, _height;
	const int _horPixels, _vertPixels;
	std::vector<std::vector<int>> _pixels;

public:
	Canvas(const Point& center = {0, 0}, double width = 16, double height = 9, int horPixels = 2560, int vertPixels = 1440);
	int brightness(int i, int j) const;
	void setBrightness(int i, int j, int brightness);
	Point coord(int i, int j) const;
	void write(const std::string& filename) const;
};

#endif /* end of include guard: CANVAS_HH_PCXK8D7T */
