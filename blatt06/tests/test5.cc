#include <cassert>
#include <cmath>
#include "../header/polygon.hh"

void test_size_8()
{
    std::vector<double> x;
    std::vector<double> y;
    const double pi = 3.141;

    for (int i = 0; i < 8; i++)
    {
        x.push_back(std::cos(((i + 1) /(double) 8) * 2 * pi));
        y.push_back(std::sin(((i + 1) /(double) 8) * 2 * pi));
    }

    Polygon pol_size8 = Polygon(x, y);

    assert(std::abs(pol_size8.volume() - (2 * std::sqrt(2))) <= std::pow(10, -9));
}

int main()
{
    test_size_8();
}