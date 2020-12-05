#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <vector>

// Calculate average
double mean(const std::vector<double>& v);

// Calculate median
double median(const std::vector<double>& v);

// Calculate momen
double moment(const std::vector<double>& v, int k);

// Calculate standart deviation
double standard_deviation(const std::vector<double>& v);

#endif // STATISTICS_HH