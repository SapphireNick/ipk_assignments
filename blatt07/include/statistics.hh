#ifndef STATISTICS_HH_8Q2JGVUD
#define STATISTICS_HH_8Q2JGVUD

#include <vector>
#include <cmath>
#include <algorithm>

template <typename T>
double mean(const T& v)
{
	double r{};

	for (auto&& e : v) {
		r += e;
	}
	return r / v.size();
}

template <typename T>
double median(T v)
{
	std::sort(v.begin(), v.end());
	return v.size() % 2 ? v[v.size() / 2] : (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
}

template <typename T>
double moment(const T& v, int k)
{
	double r{};

	for (auto&& e : v) {
		r += std::pow(e, k);
	}
	return r / v.size();
}

template <typename T>
double standard_deviation(const T& v)
{
	double m{mean(v)}, r{};

	for (auto&& e : v) {
		r += std::pow(e - m, 2);
	}
	return std::sqrt(r / v.size());
}

template <typename T>
double robust_median(const T& c)
{
	std::vector<typename T::value_type> v{c.begin(), c.end()};

	std::sort(v.begin(), v.end());
	return v.size() % 2 ? v[v.size() / 2] : (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
}

#endif /* end of include guard: STATISTICS_HH_8Q2JGVUD */
