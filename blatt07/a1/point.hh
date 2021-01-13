#ifndef POINT_HH
#define POINT_HH

#include "array"
#include "cmath"

template<typename Coord, int dim>
class Point{

private:
	std::array<Coord, dim> _coordinates; 

public:

	//using Coordinate = Coord;
	static const int dimension = dim;

	// Empty constructor
	//Point() : _coordinates() {}

	// Constructor taking coordinates
	Point(const std::array<Coord, dim>& coordinates = std::array<Coord, dim> {}) //warum die geschweiften Klammern hinter dim
		: _coordinates{coordinates} {}
	
	Coord& x(int i) { return _coordinates[i]; }
	
	double norm() const 
	{
		double sum = 0;
		
		for (auto entry : _coordinates){
				sum += std::pow(entry, 2);
		}
		
		return sqrt(sum);
	}
	
	Coord& operator[](int i) { return _coordinates[i]; }
	
	const Coord& operator[](int i) const { return _coordinates[i]; }
};

#endif //POINT_HH
