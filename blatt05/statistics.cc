#include "statistics.hh"

#include <cmath>
#include <algorithm>

namespace statistics
{
	//b
	/**
	* @brief: returns mean
	*
	* @param: const std::vector<double>& v
	*
	* @return: double
	*/
	double mean(const std::vector<double>& v)
	{
		double r{};

		for (auto&& e : v) {
			r += e;
		}
		return r / v.size();
	}

	//c
	/**
	* @brief: returns median
	*
	* @param: const std::vector<double>& v
	*
	* @return: double
	*/
	double median(const std::vector<double>& v)
	{
		auto vs{ v };
		std::sort(vs.begin(), vs.end());
		return v.size() % 2 ? vs[v.size() / 2] : (vs[v.size() / 2] + vs[v.size() / 2 - 1])/2;
	}

	//d
	/**
	* @brief: returns moment
	*
	* @param: const std::vector<double>& v
	*       : int k
	*
	* @return: double
	*/
	double moment(const std::vector<double>& v, int k)
	{
		double r{};

		for (auto&& e : v) {
			r += std::pow(e, k);
		}
		return r / v.size();	
	}

	//e
	/**
	* @brief: returns standard deviation
	*
	* @param: const std::vector<double>& v
	*
	* @return: double
	*/
	double standard_deviation(const std::vector<double>& v)
	{
		double m{mean(v)};
		double r{};

		for (auto&& e : v) {
			r += std::pow(e - m, 2);
		}
		return std::sqrt(r / v.size());
	}
} /* statistics */ 
