#include <cassert>
#include <cmath>
#include "../header/polygon.hh"

void test_size_4()
{
    std::vector<double> x;
    std::vector<double> y;
    const double pi = 3.141;

    for (int i = 0; i < 4; i++)
    {
        x.push_back(std::cos(((i + 1) /(double) 4) * 2 * pi));
        y.push_back(std::sin(((i + 1) /(double) 4) * 2 * pi));
    }

    Polygon pol_size4 = Polygon(x, y);

    assert(std::abs(pol_size4.volume() - 2) <= std::pow(10, -9));
}

int main()
{
    test_size_4();
}