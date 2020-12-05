#include <iostream>
#include <vector>
#include <cmath>
#include "header/io.hh"
#include "header/statistics.hh"

int main(int argc, char** argv)
{
    std::vector<double> input;
    input = read_vector();
    for (double& entry : input)
    {
        std::cout << entry << " ";
    }
    std::cout << std::endl;

    double input_mean = mean(input);
    double std_dev = standard_deviation(input);

    std::cout << "Mean: " << input_mean << std::endl;
    std::cout << "Median: " << median(input) << std::endl;
    std::cout << "(2nd) Moment: " << moment(input, 2) << std::endl;
    std::cout << "(3rd) Moment: " << moment(input, 3) << std::endl;
    std::cout << "Standard deviation: " << std_dev << std::endl;

    // 1e) Check relation
    std::cout << "Check relation: " << std::pow(std_dev, 2) << " =? "
                                    << moment(input, 2) - input_mean*input_mean
                                    << std::endl;
}