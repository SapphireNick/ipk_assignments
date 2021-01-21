#ifndef ITERATIONRESULT_HH
#define ITERATIONRESULT_HH

# include "point.hh"

class IterationResult{
	private: 
	 Point _point;
	 int _numIt;

	public:
	 IterationResult() : _point(Point(0,0)), _numIt(0) {}
	 IterationResult(Point& point, int numIt) : _point(point), _numIt(numIt) {}
	 
	 Point getlastpoint() {return _point;}
	 int getnumIt() const {return _numIt;}
};

#endif  // ITERATIONRESULT_HH
