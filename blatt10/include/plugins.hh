#ifndef PLUGINS_HH_CHFPZTZK
#define PLUGINS_HH_CHFPZTZK

#include <map>
#include <iostream>
#include <string>

template <typename Map>
class AnalysisPlugin {
public:

	using Data = typename Map::key_type;

	virtual ~AnalysisPlugin() = default;

	virtual std::string name() const = 0;

	virtual void printStatistics(const Map& map) {}
};

template <typename Map>
class PrintTotalCount : public AnalysisPlugin<Map> {

	std::string name() const override { return "PrintTotalCount"; }

	void printStatistics(const Map& map) override
	{
		std::size_t total{};
		for (auto&& e : map) total += e.second;
		std::cout << "total: " << total << '\n';
	}
};

template <typename Map>
class PrintFrequencies : public AnalysisPlugin<Map> {

	std::string name() const override { return "PrintFrequencies"; }

	void printStatistics(const Map& map) override
	{
		std::size_t total{};
		for (auto&& e : map) total += e.second;
		for (auto&& e : map)
			std::cout << e.first << ": " << static_cast<double>(e.second) / total << '\n';
	}
};

#endif /* end of include guard: PLUGINS_HH_CHFPZTZK */
