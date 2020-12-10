#include <iostream>

namespace power
{
    // O(n) because of for-loop
    int iterative(int q, int n)
    {
        int tmp = 1;
        
        for (int i = 0; i < n; i++)
        {
            tmp *= q;
        }
        return tmp;
    }

    // O(log n) because of recursive definition of powers used
    int recursive(int q, int n)
    {
        int tmp;

        if (n == 0) return 1;

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
} // end namespace power

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