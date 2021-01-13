#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <vector>
#include <cmath>
#include <iostream>

template<typename T>
double mean(const T& v) {
  auto sum = 0;
  for (auto e : v) sum += e;

  return sum / v.size();
}

template<typename T>
double median(const T& v) {
  if (v.size() == 0) return 0;

  auto v2(v);
  std::sort(v2.begin(), v2.end());

  if (v.size() % 2 == 0) {
    return 0.5 * (v2[v.size() / 2 - 1] + v2[v.size() / 2]);
  } else {
    return v2[(v.size() + 1) / 2 - 1];
  }
}

template<typename T>
double moment(const T& v, int k) {
  auto sum = 0;
  for (auto e : v) sum += std::pow(e, k);

  return sum / v.size();
}

template<typename T>
double std_dev(const T& v) {
  auto m = mean(v);
  auto sum = 0;
  for (auto e : v) sum += (m - e) * (m - e);

  return std::sqrt(sum / v.size());
}

template<typename T>
void statistics(const std::vector<T>& v) {
  std::cout << "mean: " << mean(v) << std::endl;
  std::cout << "median: " << median(v) << std::endl;
  std::cout << "second moment: " << moment(v, 2) << std::endl;
  std::cout << "std_dev: " << std_dev(v) << std::endl;
}

#endif //STATISTICS_HH
