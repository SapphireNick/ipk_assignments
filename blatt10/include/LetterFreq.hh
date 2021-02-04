#ifndef LETTERFREQ_HH
#define LETTERFREQ_HH

#include "frequencysource.hh"
#include <iostream>

template<typename Map>
class LetterFrequencies
{
private:
    Map _data;
    int _total_char_count;

public:
    // Procces all letter obtained from source
    template<typename Source>
    void readData(Source& source)
    {
        while(true)
        {
            auto data = source.next();
            if(!data.second) break;
            if(!std::isalpha(data.first)) continue;

            data.first = std::toupper(data.first);
            _data[data.first]++;
            _total_char_count++;
        }
    }

    // prints all the read letters with the corresponding frequencies
    void print_frequencies()
    {
        for (auto& entry : _data)
            std::cout << entry.first << " : " << (double) entry.second / (_total_char_count / entry.second) << std::endl;
    }

    // does the statistics and prints to stdout
    void PrintStatistics()
    {
        // TODO
    }

    LetterFrequencies(): _total_char_count(0){};
};

#endif // LETTERFREQ_HH