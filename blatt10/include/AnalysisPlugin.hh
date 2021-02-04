#ifndef ANALYSISPLUGIN_HH
#define ANALYSISPLUGIN_HH

#include "Filter.hh"
#include <iostream>

template<typename Map>
class AnalysisPlugin
{
public:
    using Data = typename Map::key_type;

    virtual ~AnalysisPlugin(){}

    virtual std::string name() const = 0;

    virtual void PrintStatistics(const Map& map) {}
};

template<typename Map>
class PrintTotalCount : public AnalysisPlugin<Map>
{
public:
    unsigned int _totalCount = 0;
    
public:
    virtual ~PrintTotalCount(){}

    std::string name() const override { return "PrintTotalCount"; }

    virtual void PrintStatistics(const Map& map) override
    {
        for (auto& e : map)
            _totalCount += e.second;

        std::cout << _totalCount << std::endl;
    }
};

template<typename Map>
class PrintFrequencies : public PrintTotalCount<Map>
{
private:
    unsigned int _totalCount = 0;

public:
    virtual ~PrintFrequencies(){}

    std::string name() const override { return "PrintFrequencies"; }

    void PrintStatistics(const Map& map) override
    {
        for (auto& entry : map)
            _totalCount += entry.second;

        for (auto& entry : map)
            std::cout << entry.first << " : " << static_cast<double>(entry.second) / _totalCount << std::endl;
    }
};

#endif // ANALYSISPLUGIN_HH