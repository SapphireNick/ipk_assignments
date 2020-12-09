#include "statistics.hh"
#include "io.hh"
#include <iostream>
#include <vector>
#include <cmath>

double mean(const std::vector<double>& v)
{
	double sum = 0;
	for (auto entry: v){
			sum += entry;
	}
	double result = sum / v.size();
	return result;
}

double median(std::vector<double>& v)
{
	int N = v.size();
	std::sort(v.begin(), v.end());
	if (N % 2 != 0){
		return v[((N + 1))/ 2 - 1];
	}
	else {
		return (0.5 * (v[(N / 2) - 1] + v[N / 2])); 
	}
}

double moment(const std::vector<double>& v, int k)
{
		int N = v.size();
		double result = 0;
		
		for (int i = 0; i < N; ++i){
				result += pow(v[i], k);
		}
		return result/N;
}

double standard_deviation(const std::vector<double>& v)
{
		double men = mean(v);
		std::vector<double> v_mean;
		
		for (auto entry : v){
				v_mean.push_back(entry - men);
		}
		
		double s = sqrt(moment(v_mean, 2));
		
		if (moment(v_mean, 2) == moment(v, 2) - moment(v, 2)){
			std::cout << "condition true" << std::endl;
		}
			
		return s; 
}
