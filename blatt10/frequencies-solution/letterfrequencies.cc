#include <cctype>
#include <iostream>
#include <map>

std::map<char, int> get_frequencies() {
  std::map<char, int> f;

  while (true) {
    unsigned char c;
    // read in character
    std::cin >> c;
    // abort if input closed
    if (not std::cin) break;

    if (std::isalpha(c)) {
      f[std::toupper(c)] += 1;
    }
  }

  return f;
}

void print_frequencies(const std::map<char, int>& frequencies) {
  std::size_t total = 0;

  for (auto entry : frequencies) total += entry.second;

  for (auto entry : frequencies)
    std::cout << entry.first << ": "
              << static_cast<double>(entry.second) / total << std::endl;
}

int main() {
  print_frequencies(get_frequencies());
  return 0;
}
