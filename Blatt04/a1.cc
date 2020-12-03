#include <iostream>
#include <vector> // for vector<T>
#include <utility> // for pair
#include <algorithm> // for sort
#include <cmath> // for round

namespace a1
{
    // forward declaration
    void print_vector(std::vector<double>& v);
    std::pair<double, double> find_biggest_smallest(std::vector<double> v);
    std::vector<double> reversed(const std::vector<double>& v);
    void round_entries(std::vector<double>& v);
    void reverse_swap(std::vector<double>& v);
} // End namespace a1

int main(int argc, char** argv)
{
    int vec_type;
    int int_input;
    double double_input;
    std::vector<double> double_v;

    std::cout << "A1a [1] | A1b [2] | A1c [3] | A1d [4] | A1e [5]: " << std::flush;
    std::cin >> int_input;
  
    std::cout << "Enter entries: " << std::flush;
    while(std::cin >> double_input)
    {
        double_v.push_back(double_input);
    }

    std::vector<double> tmp = a1::reversed(double_v);

    switch (int_input)
    {
        case 1:
        {
            a1::print_vector(double_v);
            break;
        }
        
        case 2:
        {
            std::pair<double, double> maxmin = a1::find_biggest_smallest(double_v);
            std::cout << "max = " << maxmin.first << 
                ", min = " << maxmin.second << std::endl;
            break;
        }

        case 3:
        {
            a1::print_vector(tmp);
            break;
        }

        case 4:
        {
            a1::round_entries(double_v);
            a1::print_vector(double_v);
            break;
        }

        case 5:
        {
            a1::reverse_swap(double_v);
            a1::print_vector(double_v);
            break;
        }

        default:
            break;
    }
}

void a1::print_vector(std::vector<double>& v)
{
    for(int entry : v)
    {
        std::cout << entry << std::endl;
    }
}

std::pair<double, double> a1::find_biggest_smallest(std::vector<double> v)
{
    std::sort(v.begin(), v.end());
    return std::make_pair(v[0], v[v.size() - 1]);
}

std::vector<double> a1::reversed(const std::vector<double>& v)
{
    int n = v.size();
    std::vector<double> reversed;

    for(int i = 0; i < n; i++)
    {
        reversed.push_back(v[n - i - 1]);
    }

    return reversed;
}

void a1::round_entries(std::vector<double>& v)
{
    for(double& entry : v)
    {
        entry = std::round(entry);
    }
}

void a1::reverse_swap(std::vector<double>& v)
{
    int n = v.size();

    for(int i = 0; i < n/2; i++)
    {
        std::swap(v[i], v[n - i - 1]);
    }
}