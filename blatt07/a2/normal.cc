#include <iostream>

#include "io.hh"
#include "statistics.hh"

int main() {
  int N = 1000;
  double mean = 0.0;
  double std_dev = 1.0;
  auto v = normal_distribution(0, N, mean, std_dev);

  statistics(v);
}
