#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include "LetterFreq.hh"

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
        LetterFrequencies<std::unordered_map<char, int>> letfreq; 
        for (int i = 1; i < argc; i++)
        {
            std::ifstream f(argv[i]);

            auto source = streamLetterSource(f);
            letfreq.readData(source);
        }

        letfreq.print_frequencies();
    }
    else
    {
        LetterFrequencies<std::map<char, int>> letfreq; 
        for (int i = 1; i < argc; i++)
        {
            std::ifstream f(argv[i]);

            auto source = streamLetterSource(f);
            letfreq.readData(source);
        }

        letfreq.print_frequencies();
    }
    
}