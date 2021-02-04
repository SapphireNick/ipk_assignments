#include "frequencies.hh"
#include "filters.hh"
#include <fstream>

int main(int argc, char** argv)
{
	using Map = std::map<char, int>;
	Frequencies<Map, CharFilter> lf;
	lf.addPlugin(std::make_shared<PrintTotalCount<Map>>());
	lf.addPlugin(std::make_shared<PrintFrequencies<Map>>());

	using uMap = std::unordered_map<char, int>;
	Frequencies<uMap, CharFilter> lfuo;
	lfuo.addPlugin(std::make_shared<PrintTotalCount<uMap>>());
	lfuo.addPlugin(std::make_shared<PrintFrequencies<uMap>>());

	for (int i = 1; i < argc; ++i) {
		std::ifstream f{argv[i]};
		auto source = streamLetterSource<std::ifstream>(f);
		lf.readData(source);
	}
	std::cout << "ordered:" << '\n';
	lf.printStatistics();

	for (int i = 1; i < argc; ++i) {
		std::ifstream f{argv[i]};
		auto source = streamLetterSource<std::ifstream>(f);
		lfuo.readData(source);
	}
	std::cout << "unordered:" << '\n';
	lfuo.printStatistics();
	
	return 0;
}
