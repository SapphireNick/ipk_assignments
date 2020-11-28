#include <iostream>
#include <vector> // for vector<T>
#include <utility> // for pair
#include <algorithm> // for sort
#include <cmath> // for round

// forward declaration
void print_vector(std::vector<int>& v);
std::pair<int, int> find_biggest_smallest(std::vector<int> v);
std::vector<double> reversed(const std::vector<double>& v);
void round_entries(std::vector<double>& v);
void reverse_swap(std::vector<int>& v);

int main(int argc, char** argv)
{
    int vec_type;
    int int_input;
    double double_input;
    std::vector<int> int_v;
    std::vector<double> double_v;

    std::cout << "<int> or <double>? [1|else]" << std::flush;
    std::cin >> int_input;

    if (int_input == 1)
    {
        while(std::cin >> int_input)
        {
            int_v.push_back(int_input);
        }
    }
    else
    {
        while(std::cin >> double_input)
        {
            double_v.push_back(double_input);
        }
    }
    std::cout << std::endl;
    
    // 1a)
    // print_vector(int_v);

    // 1b)
    // std::pair<int, int> maxmin = find_biggest_smallest(int_v);
    // std::cout << "max = " << maxmin.first << 
    //     ", min = " << maxmin.second << std::endl;

    // 1c)
    // reversing an empty vector doesn't do anything - program just quits without output
    // const std::vector<double> rev = double_v;
    // for(double entry : reversed(rev))
    // {
    //     std::cout << entry << std::endl;
    // }

    // 1d)
    round_entries(double_v);
    for(double entry : double_v)
    {
        std::cout << entry << std::endl;
    }

    // 1e)
    // reverse_swap(int_v);
    // for(double entry : int_v)
    // {
    //     std::cout << entry << std::endl;
    // }
}

void print_vector(std::vector<int>& v)
{
    for(int entry : v)
    {
        std::cout << entry << std::endl;
    }
}

std::pair<int, int> find_biggest_smallest(std::vector<int> v)
{
    std::sort(v.begin(), v.end());
    return std::make_pair(v[0], v[v.size() - 1]);
}

std::vector<double> reversed(const std::vector<double>& v)
{
    int n = v.size();
    std::vector<double> reversed;

    for(int i = 0; i < n; i++)
    {
        reversed.push_back(v[n - i - 1]);
    }

    return reversed;
}

void round_entries(std::vector<double>& v)
{
    for(double& entry : v)
    {
        entry = std::round(entry);
    }
}

void reverse_swap(std::vector<int>& v)
{
    int n = v.size();

    for(int i = 0; i < n/2; i++)
    {
        std::swap(v[i], v[n - i - 1]);
    }
}