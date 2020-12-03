#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>

std::vector<std::array<double, 2>> read_points_from_file(std::string filename);
bool sort_by_y(std::array<double, 2> a, std::array<double, 2> b);
bool sort_by_angle(std::array<double, 2> a, std::array<double, 2> b);
double calc_det_T(std::array<double, 2> a, std::array<double, 2> b, std::array<double, 2> c);
void convex_hull(std::vector<std::array<double, 2>>& points);
void write_points_to_file(std::string filename, std::vector<std::array<double, 2>>& points);

int main(int argc, char** argv)
{
    std::string file_path;
    std::cout << "Path to file: " << std::flush;
    std::cin >> file_path;

    std::vector<std::array<double, 2>> points = read_points_from_file(file_path);

    convex_hull(points);
    write_points_to_file("hull.txt", points);
}

std::vector<std::array<double, 2>> read_points_from_file(std::string filename)
{
    std::vector<std::array<double, 2>> out;
    std::array<double, 2> row;
    std::ifstream file(filename);

    while(!file.eof())
    {
        file >> row[0];
        file >> row[1];
        out.push_back(row);
    }

    return out;
}

bool sort_by_y(std::array<double, 2> a, std::array<double, 2> b)
{
    if (a[1] < b[1])
        return true;
    if ((a[1] == b[1]) && (a[0] < b[0]))
        return true;
    else
        return false;
}

bool sort_by_angle(std::array<double, 2> a, std::array<double, 2> b)
{
    if ((a[0]*b[1] - a[1]*b[0]) > 0)
        return true;
    if ((a[0]*b[1] - a[1]*b[0]) == 0 && std::abs(a[0]) > std::abs(b[0]))
        return true;
    else
        return false;
}

double calc_det_T(std::array<double, 2> a, std::array<double, 2> b, std::array<double, 2> c)
{
    return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]);
}

void convex_hull(std::vector<std::array<double, 2>>& points)
{
    std::sort(points.begin(), points.end(), sort_by_y);

    int n = points.size();
    std::array<double, 2> tmp = points[0];
    for(int i = 1; i < n; i++)
    {
        points[i][0] -= tmp[0];
        points[i][1] -= tmp[1];
    }

    std::sort(points.begin() + 1, points.end(), sort_by_angle);

    for(int i = 1; i < n; i++)
    {
        points[i][0] += tmp[0];
        points[i][1] += tmp[1];
    }

    std::vector<std::array<double, 2>> stack;
    stack.push_back(points[0]);
    stack.push_back(points[1]);

    int i = 2;
    int stack_size;
    while(i < n)
    {
        stack_size = stack.size();
        double tmp = calc_det_T(stack[stack_size - 2], stack[stack_size - 1], points[i]);
        if (tmp > 0 || stack_size == 2)
        {
            stack.push_back(points[i]);
            i++;
        }
        else if (tmp < 0)
        {
            stack.pop_back();
        }
        else
        {
            i++;
        }
    }

    points = stack;
}

void write_points_to_file(std::string filename, std::vector<std::array<double, 2>>& points)
{
    std::ofstream file(filename);

    for(auto& entry : points)
    {
        file << entry[0] << " " << entry[1] << std::endl;
    }
}