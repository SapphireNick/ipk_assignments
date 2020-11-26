#include <iostream>
#include "power.h"

int main(int argc, char** argv)
{
    int q, n;

    std::cout << "q = " << std::flush;
    std::cin >> q;
    std::cout << "n = " << std::flush;
    std::cin >> n;

    if (n < 0)
    {
        std::cout << "Exponent keine positive ganze Zahl!" << std::endl;
        return 0;
    }

    std::cout << power::iterative(q, n) << std::endl;
    std::cout << power::recursive(q, n) << std::endl;
}
