#include <iostream>

#include "io.hh"
#include "statistics.hh"

int main() {
  int N = 1000;
  double min = 0.0;
  double max = 1.0;
  auto v = uniform_distribution(0, N, min, max);

  statistics(v);
}
