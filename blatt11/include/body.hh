#ifndef BODY_HH
#define BODY_HH

#include "point.hh"
#include <array>

class Body
{
private:
    Point _pos;
    Point _vel;
    Point _acc = Point(0.0, 0.0);
    double _mass;
    std::array<int, 3> _color;

public:
    // Constructor
    Body(Point pos = Point(), Point vel = Point(), double mass = 1,
         std::array<int, 3> color = std::array<int, 3>())
    : _pos(pos), _vel(vel), _mass(mass), _color(color)
    {}

    // Accesssors
    Point& pos() { return _pos; }
    Point pos() const { return _pos; }
    Point& vel() { return _vel; }
    Point vel() const { return _vel; }
    Point& acc() { return _acc; }
    Point acc() const { return _acc; }
    double mass() const { return _mass; }
    std::array<int, 3>& colors() { return _color; }
};

#endif // BODY_HH