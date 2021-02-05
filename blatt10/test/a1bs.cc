#include "plugins.hh"
#include "frequencies.hh"
#include "filters.hh"
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	using Map = std::map<std::string, int>;
	Frequencies<Map, StringFilter> lf;
	lf.addPlugin(std::make_shared<PrintTotalCount<Map>>());
	lf.addPlugin(std::make_shared<PrintFrequencies<Map>>());

	using uMap = std::unordered_map<std::string, int>;
	Frequencies<uMap, StringFilter> lfuo;
	lfuo.addPlugin(std::make_shared<PrintTotalCount<uMap>>());
	lfuo.addPlugin(std::make_shared<PrintFrequencies<uMap>>());
	
	//Frequencies<std::map<std::string, int>, StringFilter> lf;
	//Frequencies<std::unordered_map<std::string, int>, StringFilter> lfuo;

	for (int i = 1; i < argc; ++i) {
		std::ifstream f{argv[i]};
		auto source = streamWordSource<std::ifstream>(f);
		lf.readData(source);
	}
	std::cout << "ordered:" << '\n';
	lf.printStatistics();

	for (int i = 1; i < argc; ++i) {
		std::ifstream f{argv[i]};
		auto source = streamWordSource<std::ifstream>(f);
		lfuo.readData(source);
	}
	//std::cout << "unordered:" << '\n';
	//lfuo.printStatistics();
	
	return 0;
}
