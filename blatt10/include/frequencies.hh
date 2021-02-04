#ifndef FREQUENCIES_HH_PHB02XMA
#define FREQUENCIES_HH_PHB02XMA

#include "frequencysource.hh"
#include "plugins.hh"
#include <iostream>
#include <cctype>
#include <map>
#include <memory>
#include <vector>

template <typename Map, typename Filter>
class Frequencies {
public:

	using Data = typename Map::key_type;
	using Plugin = AnalysisPlugin<Map>;

	Frequencies(Filter filter = Filter()) : _filter{filter} {}

	void addPlugin(const std::shared_ptr<Plugin> plugin) {_plugins.push_back(plugin);}

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
		for (auto&& e : _plugins) e->printStatistics(_map);
	}

private:

	Map _map;
	Filter _filter;
	std::vector<std::shared_ptr<Plugin>> _plugins;

};

#endif /* end of include guard: FREQUENCIES_HH_PHB02XMA */
