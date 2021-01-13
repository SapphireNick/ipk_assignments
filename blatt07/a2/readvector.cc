#include <iostream>

#include "io.hh"
#include "statistics.hh"

int main() {
  auto v = read_vector();

  statistics(v);
}
