#ifndef LETTERFREQ_HH
#define LETTERFREQ_HH

#include "frequencysource.hh"
#include "statistics.hh"
#include <iostream>

template<typename Map>
class LetterFrequencies
{
private:
    Map _data;

public:
    // Procces all letter obtained from source
    template<typename Source>
    void readData(Source& source)
    {
        auto source = streamLetterSource(std::cin)

        while(true)
        {
            auto data = source.next();
            if(!data.second) break;
            if(!std::isalpha(data.first)) continue;

            data.first = std::toupper(data.first);
            _data[data.first]++;
        }
    }

    // prints all the read letters with the corresponding frequencies
    void print_frequencies()
    {
        for (auto& entry : _data)
            std::cout << entry.first << " : " << entry.second << std::endl;
    }

    // does the statistics and prints to stdout
    void PrintStatistics()
    {
        // TODO
    }
};

#endif // LETTERFREQ_HH