#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <vector>
#include <iostream>
#include <vector>
#include <cmath>

double mean(const std::vector<double>& v);

double median(std::vector<double>& v);

double moment(const std::vector<double>& v, int k);

double standard_deviation(const std::vector<double>& v);

#endif // STATISTICS_HH
