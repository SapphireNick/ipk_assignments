#ifndef FILTERS_HH_JX21DTUW
#define FILTERS_HH_JX21DTUW

#include <cctype>
#include <string>

class CharFilter {
public:

	char transform(const char& data)
	{
		return std::toupper(data);
	}

	bool remove(const char& data)
	{
		return std::isalpha(data);
	}
};

class StringFilter {
public:

	std::string transform(const std::string& data)
	{
		std::string s{};
		for (auto&& e : data) s += toupper(e);
		return s;
	}

	bool remove(const std::string& data)
	{
		for (auto&& e : data) 
			if (!isalpha(e))
				return false;
		return true;
	}
};

#endif /* end of include guard: FILTERS_HH_JX21DTUW */
