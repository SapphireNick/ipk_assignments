#ifndef ITERATIONRESULT_HH
#define ITERATIONRESULT_HH

#include "point.hh"

class IterationResult
{
private:
    Point _res;
    int _perfIterations;

public:
    // Accessor-methods returning a ref to the property
    Point& getPoint() { return _res; }
    int& getPerfIter() { return _perfIterations; }

    // Constructor
    IterationResult() : _res(Point(0, 0)), _perfIterations(0){}
    IterationResult(Point& res, int perfIterations)
    : _res(res), _perfIterations(perfIterations){}
};

#endif // ITERATIONSRESULT_HH
