#ifndef POINT_HH
#define POINT_HH

class Point {
 public:
  // default constructor
  Point() : _x(0.0), _y(0.0) {}

  // constructor für übergebene Koordinaten
  Point(double x, double y) : _x(x), _y(y) {}

  // Accessors

  double x() const { return _x; }

  double y() const { return _y; }

 private:
  double _x;
  double _y;
};

#endif  // POINT_HH
