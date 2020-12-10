#include "../header/statistics.hh"
#include <algorithm>
#include <cmath>

double mean(const std::vector<double>& v)
{
    double sum = 0;

    for(auto& entry : v)
    {
        sum += entry;
    }
    return sum / v.size();
}

double median(const std::vector<double>& v)
{
    int n = v.size();
    std::vector<double> v_sorted = v;
    std::sort(v_sorted.begin(), v_sorted.end());

    if (n == 0)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 0.5 * (v_sorted[n/2 - 1] + v_sorted[n/2]);
    }
    else
    {
        return v_sorted[n/2];
    }
}

double moment(const std::vector<double>& v, int k)
{
    double sum = 0;

    for(auto& entry : v)
    {
        sum += std::pow(entry, k);
    }
    return sum / v.size();
}

double standard_deviation(const std::vector<double>& v)
{
    std::vector<double> tmp = v;
    double v_mean = mean(v);

    for (auto& entry : tmp)
    {
        entry = std::pow(entry - v_mean, 2);
    }
    return std::sqrt(mean(tmp));
}