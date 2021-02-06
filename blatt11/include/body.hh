#ifndef BODY_HH
#define BODY_HH

#include "point.hh"
#include <array>

class Body
{
private:
    Point _pos;
    Point _vel;
    std::array<int, 3> _color;

public:
    // Constructor
    Body(Point pos = Point(), Point vel = Point(),
         std::array<int, 3> color = std::array<int, 3>())
    : _pos(pos), _vel(vel), _color(color)
    {}

    // Accesssors
    Point& pos() { return _pos; }
    Point& vel() { return _vel; }
    std::array<int, 3>& colors() { return _color; }
};

#endif // BODY_HH