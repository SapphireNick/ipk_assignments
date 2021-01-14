#ifndef POINT_HH
#define POINT_HH

#include <array>
#include <cmath>

template<typename Coord, int dim>
class Point {
 public:
  static const int dimension = dim;

  // Empty constructor
  Point()
  {
    for (int i = 0; i < dim; i++)
    {
      _point[i] = 0;
    }
  }

  // Constructor taking coordinates
  Point(std::array<Coord, dim> point) : _point(point) {}

  // Accessor method
  // Coord& x(int i)
  // {
  //   return _point[i];
  // }
  Coord& operator[](int i)
  {
    return _point[i];
  }

  const Coord& operator[](int i) const
  {
    return _point[i];
  }
  
  // Norm
  double norm()
  {
    double norm = 0;

    for(int i = 0; i < dim; i++)
    {
      norm += std::pow(_point[i], 2);
    }

    return std::sqrt(norm);
  }

 private:
  std::array<Coord, dim> _point;
};

#endif  // POINT_HH
