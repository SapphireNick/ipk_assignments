#include <cassert>
#include <cmath>
#include "../header/polygon.hh"

void test_empty()
{
    std::vector<Point> empty;
    Polygon empty_pol = Polygon(empty);

    assert(empty_pol.volume() == 0);
}

void test_size_1()
{
    std::vector<Point> s1;
    s1.push_back(Point(0.5, 0.5));
    Polygon s1_pol = Polygon(s1);

    assert(s1_pol.volume() == 0);
}

void test_size_2()
{
    std::vector<Point> s2;
    s2.push_back(Point(0.5, 0.5));
    s2.push_back(Point(0.6, 0.6));
    Polygon s2_pol = Polygon(s2);

    assert(s2_pol.volume() == 0);
}

int main()
{
    test_empty();
    test_size_1();
    test_size_2();
}