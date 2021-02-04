#ifndef FILTER_HH
#define FILTER_HH

#include <string>

class CharFilter
{
public:
    char transform(const char& c)
    {
        return std::toupper(c);
    }

    bool remove(const char& c)
    {
        return !std::isalpha(c);
    }
};

class StringFilter
{
public:
    std::string transform(const std::string& str)
    {
        std::string out = "";
        for (auto e : str)
        {
            out += std::toupper(e);
        }

        return out;
    }

    bool remove(const std::string& str)
    {
        for (auto e : str)
        {
            if(!std::isalpha(e)) return true;
        }

        return false;
    }
};

#endif // FILTER_HH