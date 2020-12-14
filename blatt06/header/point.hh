#ifndef POINT_HH
#define POINT_HH

class Point
{
private:
    double _x;
    double _y;

public:
    // Default constructor
    Point();
    // Parameterized constructor to declare coordinates
    Point(double x, double y);

    // accessor methods
    double x() const;
    double y() const;
};

#endif // POINT_HH