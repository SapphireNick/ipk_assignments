#ifndef CHARFREQUENCY_HH
#define CHARFREQUENCY_HH

#include <iostream>
#include <map>

std::map<char, int> get_frequencies();
void print_frequencies(const std::map<char, int>& frequencies, int total_char_amount);

#endif // CHARFREQUENCY_HH