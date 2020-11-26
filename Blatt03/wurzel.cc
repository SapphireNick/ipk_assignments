#include <iostream>

double root_iterative(double q, int n, int steps);
void test_root(double q, int n, int steps);

// Copied recursive power function from previous task but now takes and returns doubles instead of int
namespace power
{
    // O(log n) because of recursive definition of powers used
    double recursive(double q, int n)
    {
        double tmp;

        if (n < 0)
        {
            std::cout << "Exponent keine positive ganze Zahl!" << std::endl;
            return 0;
        }
        else if (n == 0)
        {
            return 1;
        }
        else if (n%2 == 0)
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
    double q;
    int n, steps;

    std::cout << "q = " << std::flush;
    std::cin >> q;
    std::cout << "n = " << std::flush;
    std::cin >> n;
    std::cout << "steps = " << std::flush;
    std::cin >> steps;

    std::cout << root_iterative(q, n, steps) << std::endl;
    test_root(q, n, steps);
}

double root_iterative(double q, int n, int steps)
{
    double tmp = 1;

    if (n < 0)
    {
        std::cout << "Eingabe für n ist negativ! Keine Wurzel berechnet" << std::endl;
        return 0;
    }
    if (n == 0)
    {
        std::cout << "0-te Wurzel existiert nicht" << std::endl;
        return 0;
    }
    if (n == 1)
    {
        return q;
    }

    for (int i = 0; i < steps; i++)
    {
        tmp = tmp + (1 / (double) n) * ((q / power::recursive(tmp, n - 1)) - tmp);
    }
    
    return tmp;
}

void test_root(double q, int n, int steps)
{
    if (n == 0){ return; }

    double approx = root_iterative(q, n, steps);
    double exp = power::recursive(approx, n);

    std::cout << "q = " << q << ", n = " << n << ", steps = " << steps << ", q - approx^n = " << q - exp << std::endl;
} 