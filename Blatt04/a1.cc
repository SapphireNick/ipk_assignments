#include <iostream>
#include <vector> // for vector<T>
#include <utility> // for pair
#include <algorithm> // for sort
#include <cmath> // for round

void print_vector(std::vector<int>& v);
std::pair<int, int> find_biggest_smallest(std::vector<int> v);
std::vector<double> reversed(const std::vector<double>& v);
void round_entries(std::vector<double>& v);
void reverse_swap(std::vector<int>& v);

int main(int argc, char** argv)
{
    // 1a)
    // std::vector<int> a = {1, 2, 3, 4, 5};
    // print_vector(a);

    // 1b)
    // initialize and test vectors b and c
    // std::vector<int> b = {20, 4, 6, 28, 10};
    // std::vector<int> c = {6, 5, 4, 3, 2, 1};
    // std::pair<int, int> minmaxB = find_biggest_smallest(b);
    // std::pair<int, int> minmaxC = find_biggest_smallest(c);

    // std::cout << "max(b) = " << minmaxB.first << 
    //     ", min(b) = " << minmaxB.second << std::endl;
    // std::cout << "max(c) = " << minmaxC.first << 
    //     ", min(c) = " << minmaxC.second << std::endl;

    // 1c)
    // reversing an empty vector doesn't do anything - program just quits without output
    // const std::vector<double> d = {2.6, 4.5, 93.2, 28, 10};
    // const std::vector<double> e;
    // std::vector<double> f = reversed(e);
    // for(double entries : f)
    // {
    //     std::cout << entries << std::endl;
    // }

    // 1d)
    // std::vector<double> d = {2.6, 4.5, 93.2, 28, 10};
    // round_entries(d);

    // for(double entry : d)
    // {
    //     std::cout << entry << std::endl;
    // }

    // 1e)
    std::vector<int> d = {2, 4, 93, 28, 10};
    reverse_swap(d);

    for(double entry : d)
    {
        std::cout << entry << std::endl;
    }
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
    int n = v.size();

    for(int i = 0; i < n; i++)
    {
        v[i] = std::round(v[i]);
    }
}

// doesnt work TODO
void reverse_swap(std::vector<int>& v)
{
    int n = v.size();

    for(int i = 0; i < n; i++)
    {
        std::swap(v[i], v[n - i - 1]);
    }
}