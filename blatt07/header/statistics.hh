#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

// Return the mean
template<typename T>
double mean(const T& v)
{
    double sum = 0;
    for (auto e : v) sum += e;

    return sum / v.size();
}

// Return the median
template<typename T>
double median(const T& v)
{
    if (v.size() == 0) return 0;

    auto v2(v);
    std::sort(v2.begin(), v2.end());

    if (v.size() % 2 == 0)
    {
        return 0.5 * (v2[v.size() / 2 - 1] + v2[v.size() / 2]);
    }
    else
    {
        return v2[(v.size() + 1) / 2 - 1];
    }
}

// Return the k'th moment
template<typename T>
double moment(const T& v, int k)
{
    double sum = 0;
    for (auto e : v) sum += std::pow(e, k);

    return sum / v.size();
}

// Return the standard deviation
template<typename T>
double std_dev(const T& v)
{
    double m = mean(v);
    double sum = 0;
    for (auto e : v) sum += (m - e) * (m - e);

    return std::sqrt(sum / v.size());
}

// robust iplementation for median
template<typename T>
double robust_median(const T& v)
{
    std::vector<typename T::value_type> tmp;
    tmp.resize(v.size());
    std::copy(v.begin(), v.end(), tmp.begin());
    
    return median(tmp);
}

// Return a variety of statistics
template<typename T>
void statistics(const T& v)
{
    std::cout << "mean: " << mean(v) << std::endl;
    std::cout << "median: " << median(v) << std::endl;
    std::cout << "second moment: " << moment(v, 2) << std::endl;
    std::cout << "std_dev: " << std_dev(v) << std::endl;
}

#endif  // STATISTICS_HH
