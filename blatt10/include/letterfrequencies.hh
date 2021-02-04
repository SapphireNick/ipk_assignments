#ifndef LETTERFREQUENCIES_HH_NXITHWHT
#define LETTERFREQUENCIES_HH_NXITHWHT

#include "frequencysource.hh"
#include <iostream>
#include <cctype>
#include <map>

template <typename Map>
class LetterFrequencies {

	Map _map;

public:

	template <typename Source>
	void readData(Source& source)
	{
		while (true) {
			auto data = source.next();
			if (!data.second) break;

			if (std::isalpha(data.first)) _map[std::toupper(data.first)] += 1;
		}
	}

	void printStatistics()
	{
		std::size_t total = 0;

		for (auto&& e : _map) total += e.second;

		for (auto&& e : _map)
			std::cout << e.first << ": " << static_cast<double>(e.second) / total << '\n';
	}

};

#endif /* end of include guard: LETTERFREQUENCIES_HH_NXITHWHT */
