#ifndef STATISTICS_HH_8Q2JGVUD
#define STATISTICS_HH_8Q2JGVUD

#include <vector>

namespace statistics
{
	double mean(const std::vector<double>& v);
	double median(const std::vector<double>& v);
	double moment(const std::vector<double>& v, int k);
	double standard_deviation(const std::vector<double>& v);
} /* statistics */ 

#endif /* end of include guard: STATISTICS_HH_8Q2JGVUD */
