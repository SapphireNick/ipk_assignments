#include <iostream>
#include <cassert>
#include <cmath>
#include "../header/statistics.hh"

void run_tests()
{
    std::vector<double> empty;
    std::vector<double> e4 = {1, 2, 3, 4};
    std::vector<double> e5 = {5, 2, 3, 1, 4};

    assert(median(empty) == 0);
    assert(median(e4) == 2.5);
    assert(median(e5) == 3);
}

int main()
{
    run_tests();
}