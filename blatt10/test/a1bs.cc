#include "frequencies.hh"
#include "filters.hh"
#include <fstream>

int main(int argc, char** argv)
{
	Frequencies<std::map<std::string, int>, StringFilter> lf;
	Frequencies<std::unordered_map<std::string, int>, StringFilter> lfuo;

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
	std::cout << "unordered:" << '\n';
	lfuo.printStatistics();
	
	return 0;
}
