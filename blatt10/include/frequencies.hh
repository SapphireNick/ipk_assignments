#ifndef FREQUENCIES_HH_PHB02XMA
#define FREQUENCIES_HH_PHB02XMA

#include "frequencysource.hh"
#include <iostream>
#include <cctype>
#include <map>

template <typename Map, typename Filter>
class Frequencies {

	Map _map;
	Filter _filter;

	typedef typename Map::key_type Data;

public:

	Frequencies(Filter filter = Filter()) : _filter{filter} {}

	template <typename Source>
	void readData(Source& source)
	{
		while (true) {
			auto data = source.next();
			if (!data.second) break;

			if (_filter.remove(data.first)) _map[_filter.transform(data.first)] += 1;
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

#endif /* end of include guard: FREQUENCIES_HH_PHB02XMA */
