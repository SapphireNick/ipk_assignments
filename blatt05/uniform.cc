#include <iostream>
#include <vector>
#include <cmath>
#include "header/io.hh"
#include "header/statistics.hh"

// release build is about 4x faster than debug build
int main(int argc, char** argv)
{
    std::vector<double> input = uniform_distribution(random_seed(), std::pow(10, 6), 0, 10);
    // for (double& entry : input)
    // {
    //     std::cout << entry << " ";
    // }
    // std::cout << std::endl;

    std::cout << "Mean: " << mean(input) << std::endl;
    std::cout << "Median: " << median(input) << std::endl;
    std::cout << "(2nd) Moment: " << moment(input, 2) << std::endl;
    std::cout << "(3rd) Moment: " << moment(input, 3) << std::endl;
    std::cout << "Standard deviation: " << standard_deviation(input) << std::endl;

    std::cout << "Check for relation in readvector programm" << std::endl;
}