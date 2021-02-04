#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include "Frequencies.hh"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./test_letterfreq_compl [path_to_file_1] ...\n";
        return -1;
    }

    int input;
    do
    {
        std::cout << "Unordered Map[1] or Map[2] ?: ";
        std::cin >> input;
    } while (input != 1 && input != 2);

    if (input == 1)
    {
        using WordMap = std::unordered_map<std::string, int>;
        StringFilter stringFilter;

        Frequencies<WordMap, StringFilter> letfreq(stringFilter); 
        for (int i = 1; i < argc; i++)
        {
            std::ifstream f(argv[i]);

            auto source = streamWordSource(f);
            letfreq.readData(source);
        }

        letfreq.addPlugin(std::make_shared<PrintTotalCount<WordMap>>());
        letfreq.addPlugin(std::make_shared<PrintFrequencies<WordMap>>());
        letfreq.PrintStatistics();
    }
    else
    {
        using WordMap = std::map<std::string, int>;
        StringFilter stringFilter;

        Frequencies<WordMap, StringFilter> letfreq(stringFilter); 
        for (int i = 1; i < argc; i++)
        {
            std::ifstream f(argv[i]);

            auto source = streamWordSource(f);
            letfreq.readData(source);
        }

        letfreq.addPlugin(std::make_shared<PrintTotalCount<WordMap>>());
        letfreq.addPlugin(std::make_shared<PrintFrequencies<WordMap>>());
        letfreq.PrintStatistics();
    }
}