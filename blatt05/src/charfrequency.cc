#include "../header/charfrequency.hh"

std::map<char, int> get_frequencies()
{
    std::map<char, int> frequencies;

    while (true)
    {
        unsigned char c;
        
        // Read console input
        std::cin >> c;
        if (not std::cin)
            break;
        else if (!std::isalpha(c))
            continue;

        c = std::toupper(c);
        frequencies[c]++;
    }

    return frequencies;
}

void print_frequencies(const std::map<char, int>& frequencies, int total_char_amount)
{
    for(auto& entry : frequencies)
    {
        double tmp = entry.second;
        std::cout << entry.first << " : " << tmp/(total_char_amount - tmp) << std::endl;
    }
}