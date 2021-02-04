#ifndef LETTERFREQ_HH
#define LETTERFREQ_HH

#include "frequencysource.hh"
#include "Filter.hh"
#include "AnalysisPlugin.hh"
#include <iostream>
#include <memory>
#include <vector>

template<typename Map, typename Filter>
class Frequencies
{
using Plugin = AnalysisPlugin<Map>;

private:
    Map _data;
    Filter _filter;
    std::vector<std::shared_ptr<Plugin>> _plugins;

public:
    Frequencies(Filter filter = Filter()): _filter(filter){}

    // Add a new Plugin
    void addPlugin(const std::shared_ptr<Plugin> plugin)
    {
        _plugins.push_back(plugin);
    }

    // Procces all letter obtained from source
    template<typename Source>
    void readData(Source& source)
    {
        while(true)
        {
            auto data = source.next();
            if(!data.second) break;
            if(_filter.remove(data.first)) continue;

            _data[_filter.transform(data.first)]++;
        }
    }

    // does the statistics and prints to stdout
    void PrintStatistics()
    {
        for (auto& plugin : _plugins)
        {
            std::cout << plugin->name() << std::endl;
            plugin->PrintStatistics(_data);
        }
    }
};

#endif // LETTERFREQ_HH