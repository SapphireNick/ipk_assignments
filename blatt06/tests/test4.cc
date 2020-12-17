#include <cassert>
#include <cmath>
#include "../header/polygon.hh"

void test_size_8()
{
    std::vector<double> x;
    std::vector<double> y;
    const double pi = 3.141;

    for (int i = 0; i < 6; i++)
    {
        x.push_back(std::cos(((i + 1) /(double) 6) * 2 * pi));
        y.push_back(std::sin(((i + 1) /(double) 6) * 2 * pi));
    }

    Polygon pol_size6 = Polygon(x, y);

    assert(std::abs(pol_size6.volume() - (3/(double) 2 * std::sqrt(3))) <= 0.5);
}

int main()
{
    test_size_8();
}