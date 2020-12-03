#include <vector>
#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

namespace a2
{
	//a
	/**
	* @brief: reads points from file and returns as vector of arrays
	*
	* @param: std::string fn
	*
	* @return: 	std::vector<std::array<double, 2>>
	*/
	std::vector<std::array<double, 2>> read_points_from_file(std::string fn)
	{
		std::ifstream is{ fn };
		std::vector<std::array<double, 2>> points;
		std::array<double, 2> p;

		is >> p[0];
		is >> p[1];

		while	(is.good()) {
			points.push_back(p);
			is >> p[0];
			is >> p[1];
		}
		return points;
	}

	//b
	/**
	* @brief: returns true if a < b
	*
	* @param: std::array<double, 2> const& a
	*       : std::array<double, 2> const& b
	*
	* @return: bool
	*/
	bool sort_by_y(std::array<double, 2> const& a, std::array<double, 2> const& b)
	{
		return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
	}

	/**
	* @brief: returns true if the angle to the x axis of a < b
	*
	* @param: std::array<double, 2> const& a
	*       : std::array<double, 2> const& b
	*
	* @return: void
	*/
	bool sort_by_angle(std::array<double, 2> const& a, std::array<double, 2> const& b)
	{
		double tmp{ a[0] * b[1] - a[1] * b[0] };
		return tmp > 0 || (tmp == 0 && std::abs(a[0]) > std::abs(b[0]));
	}

	/**
	* @brief: returns true if c is to the right of the line ab
	*
	* @param: std::array<double, 2> const& a
	*       : std::array<double, 2> const& b
	*       : std::array<double, 2> const& c
	*
	* @return: bool
	*/
	bool is_right(std::array<double, 2> const& a, std::array<double, 2> const& b, std::array<double, 2> const& c)
	{
		return (b[0]-a[0])*(c[1]-a[1])-(c[0]-a[0])*(b[1]-a[1]) < 0;
	}

	/**
	* @brief: writes points to file
	*
	* @param: std::string fn
	*       : std::vector<std::array<double, 2>>& points
	*
	* @return: void
	*/
	void write_points_to_file(std::string fn, std::vector<std::array<double, 2>>& points)
	{
		std::ofstream os{ fn };
		for (auto&& p : points) {
			os << p[0] << ' ' << p[1] << '\n';
		}
	}

	/**
	* @brief: calculates the convex hull of points
	*
	* @param: std::vector<std::array<double, 2>>& points
	*
	* @return: void
	*/
	void convex_hull(std::vector<std::array<double, 2>>& points)
	{
		std::sort(points.begin(), points.end(), sort_by_y);

		std::array<double, 2> p0{ points[0] };

		for (auto&& p : points) {
			p[0] -= p0[0];
			p[1] -= p0[1];
		}
		std::sort(points.begin() + 1, points.end(), sort_by_angle);

		for (auto&& p : points) {
			p[0] += p0[0];
			p[1] += p0[1];
		}

		for (unsigned long i = 2; i < points.size(); ++i) {
			if (!is_right(points[i-2], points[i], points[i-1])) {
				points.erase(points.begin() + i - 1);
				i -= 2;
			}
		}
	}
} /* a2 */

int main(int argc, char** argv)
{
	auto points = a2::read_points_from_file(argc > 1 ? argv[1] : "points.txt");

	a2::convex_hull(points);

	a2::write_points_to_file(argc > 2 ? argv[2] : "hull.txt", points);

	return 0;
}
