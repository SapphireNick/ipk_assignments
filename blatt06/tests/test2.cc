#include <cassert>
#include <cmath>
#include "../header/polygon.hh"

void test_size_3()
{
    std::vector<double> x;
    std::vector<double> y;
    const double pi = 3.141;

    for (int i = 0; i < 3; i++)
    {
        x.push_back(std::cos(((i + 1) /(double) 3) * 2 * pi));
        y.push_back(std::sin(((i + 1) /(double) 3) * 2 * pi));
    }

    Polygon pol_size3 = Polygon(x, y);

    assert(std::abs(pol_size3.volume() - (3/(double) 4 * std::sqrt(3))) <= 0.5);
}

int main()
{
    test_size_3();
}