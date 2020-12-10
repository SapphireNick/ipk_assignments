#include <iostream>
#include <cassert>
#include <cmath>
#include "../header/statistics.hh"

void run_tests()
{
    std::vector<double> empty;
    std::vector<double> e4 = {1, 2, 3, 4};
    std::vector<double> e5 = {1, 2, 3, 4, 5};

    assert(std::isnan(mean(empty)));
    assert(mean(e4) == 2.5);
    assert(mean(e5) == 3);
    std::cout << "OK" << std::endl;
}

int main()
{
    run_tests();
}