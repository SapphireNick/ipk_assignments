#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{
    double a = 0, b = 0, c = 0;
    double tmp = 0;

    std::cout << "a = " << std::flush;
    std::cin >> a;
    std::cout << "b = " << std::flush;
    std::cin >> b;
    std::cout << "c = " << std::flush;
    std::cin >> c;

    if (a == b && a == 0)
    {
        std::cout << "Keine eindutige Lösung. ( a = b )" << std::endl;
    }

    tmp = b * b - 4 * a * c;

    if (tmp < 0)
    {
        std::cout << "Keine reelle Lösung" << std::endl;
    }
    else if (tmp == 0)
    {
        std::cout << "x = " << (-b) / (2 * a) << std::endl;
    }
    else
    {
        std::cout << "x1 = " << (-b + std::sqrt(tmp)) / 2 * a << std::endl;
        std::cout << "x2 = " << (-b - std::sqrt(tmp)) / 2 * a << std::endl;
    }
    return 0;
}