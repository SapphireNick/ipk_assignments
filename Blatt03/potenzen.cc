#include <iostream>

namespace power
{
    int interative(int q, int n)
    {
        int tmp = q;

        if (n < 0)
        {
            std::cout << "Exponent keine positive ganze Zahl!" << std::endl;
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if(n == 1)
        {
            return q;
        }
        
        for (int i = 1; i < n; i++)
        {
            tmp *= q;
        }

        return tmp;
    }

    int recursive(int q, int n)
    {
        int tmp;

        if (n < 0)
        {
            std::cout << "Exponent keine positive ganze Zahl!" << std::endl;
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (n%2 == 0)
        {
            tmp = recursive(q, n/2);
            return tmp *= tmp;
        }
        else
        {
            return q * recursive(q, n - 1);
        }
        
    }
}

int main(int argc, char** argv)
{
    int q, n;

    std::cout << "q = " << std::flush;
    std::cin >> q;
    std::cout << "n = " << std::flush;
    std::cin >> n;

    std::cout << power::interative(q, n) << std::endl;
    std::cout << power::recursive(q, n) << std::endl;
}