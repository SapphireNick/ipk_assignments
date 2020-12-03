#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <array>
#include <fstream>
#include <stack>

void printv(std::vector<std::array<double, 2>>& points)
{
	int k = 1; 
	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = 0; j < points[i].size(); ++j)
		{
			std::cout << points[i][j] << " ";
			if (k %2 == 0){std::cout << " \n";}
			k += 1;
			}
	}
}

std::vector<std::array<double, 2>> read_points_from_file(std::string filename)
{	
	std::ifstream input(filename); 
	int n = 0; 
	double a1, a2;		
	std::vector<std::array<double, 2>> points;
	
	while (input.good()) 
	{
		if (n % 2 == 0)
		{
			input >> a1; 
			}
		else
		{
			input >> a2;
			}
		n += 1; 
		if (n % 2 == 0 and n != 0)
		{
			std::array<double, 2> c = {a1, a2};
			points.push_back(c);
			n = 0;
			}
		}
	return points;
	input.close();	
	}

bool sort_by_y(std::array<double, 2> a, std::array<double, 2> b)
{
	if (a[1] < b[1]){return true;}
	if (a[1] == b[1] and a[0] < b[0]){return true;}
	else {return false;}
	}
	
bool sort_by_angle(std::array<double, 2> a, std::array<double, 2> b)
{
	if (a[0] * b[1] - a[1] * b[0] > 0){return true;}
	if (a[0] * b[1] - a[1] * b[0] == 0 and
	  std::abs(a[0]) > std::abs(b[0])) {return true;}
	else {return false;}
	}

// check if pt3 point is left of vector pt1 -> pt2
bool is_left(std::array<double, 2> pt1, std::array<double, 2> 
  pt2, std::array<double, 2> pt3)
{
	if ((pt2[0] - pt1[0]) * (pt3[1] - pt1[1]) - (pt3[0] - pt1[0]) * (pt2[1] - pt1[1]) > 0)
	{return true;}
	
	else {return false;}
	}

// create convex hull of input vector with graham scan
// scan implementation from https://de.wikipedia.org/wiki/Graham_Scan
void convex_hull(std::vector<std::array<double, 2>>& points)
{
	std::sort(points.begin(), points.end(), sort_by_y);

	std::array<double, 2> p0 = points[0]; 

	for (int i = 1; i < points.size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			points[i][j] = points[i][j] - p0[j];
			}
		}	
	
	std::sort(points.begin()+1, points.end(), sort_by_angle);
	
	for (int i = 1; i < points.size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			points[i][j] = points[i][j] + p0[j];
			}
		}
			
	// Graham-Scan implementieren mit stack 
	/*
	for (unsigned long i = 2; i < points.size(); ++i) {
			if (left_of_vector(points[i-2], points[i], points[i-1])) {
				points.erase(points.begin() + i - 1);
				i -= 2;
			}}
	printv(points);*/
	
	std::vector<std::array<double, 2>> stack;
	stack.push_back(points[0]);
	stack.push_back(points[1]);
	int l = 2;
	int n = points.size();
	
	
	while (l < n)
	{
		if (is_left(stack[1], stack[0], points[l]) == true or stack.size() == 2)
		{
			stack.push_back(points[l]);
			l = l + 1;
			}
		else {stack.pop_back();}
		}
	printv(stack);
	points = stack;
	}

void read_points_from_file(std::string filename, std::vector<std::array<double, 2>>& points)
{
	std::ofstream output(filename);
	int k = 1; 

	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			output << points[i][j] << " ";
			if (k %2 == 0){output << " \n";}
			k += 1;
			}
		}
	}


int main(int argc, char** argv)
{
	std::vector<std::array<double, 2>> points; 
	points = read_points_from_file("convex-hull-points.txt");
	
	convex_hull(points);

	read_points_from_file("convex-hull-result.txt", points);
	
	return 0;
	}
