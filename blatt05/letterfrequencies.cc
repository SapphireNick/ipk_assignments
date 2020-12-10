#include "header/charfrequency.hh"

int main(int argc, char** argv)
{
    std::map<char, int> frequencies;
    int total_char_amount = 0;

    frequencies = get_frequencies();
    for(auto& entry : frequencies)
    {
        total_char_amount += entry.second;
    }
    print_frequencies(frequencies, total_char_amount);
}