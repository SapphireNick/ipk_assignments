#include "letterfrequencies.hh"

int main(int argc, char** argv)
{
	auto source = streamLetterSource<std::istream>(std::cin);
	LetterFrequencies<std::map<char, int>> lf;
	lf.readData(source);
	lf.printStatistics();
	
	return 0;
}
