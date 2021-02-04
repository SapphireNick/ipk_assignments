#include <iostream>
#include <map>
#include <unordered_map>
#include "LetterFreq.hh"

int main()
{
    LetterFrequencies<std::map<char, int>> map;
    LetterFrequencies<std::unordered_map<char, int>> unordered_map;

    std::cout << "Please input test string:\n";

    auto source = streamLetterSource(std::cin);

    // map.readData(source);
    unordered_map.readData(source);

    // std::cout << "With ordered map:\n";
    // map.print_frequencies();
    std::cout << "\nWith unordered map:\n";
    unordered_map.print_frequencies();
}