#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

namespace aufgabe1
{
	//b
	/**
	* @brief: returns a pair containing smallest and biggest element of v
	*
	* @param: std::vector<T> v
	*
	* @return: str::pair<T, T>
	*/
	template <typename T>
	std::pair<T, T> minmax(std::vector<T> const& v)
	{
		if (v.empty()) return std::make_pair(T{}, T{});

		T min{ v[0] }, max{ v[0] };

		for (auto&& e : v) {
			if (min > e) min = e;
			if (max < e) max = e;
		}
		return std::make_pair(min, max);
	}

	//c
	/**
	* @brief: returns new vector in reverse order
	*
	* @param: const std::vector<double>& v
	*
	* @return: 	std::vector<double>
	*/
	std::vector<double> reversed(const std::vector<double>& v)
	{
		std::vector<double> r(v.size());

		for (unsigned long i = 0; i < v.size(); ++i) {
			r[i] = v[v.size() - i - 1];
		}
		return r;
	}

	//d
	/**
	* @brief: rounds all elements of vector v
	*
	* @param: std::vector<double> v
	*
	* @return: void
	*/
	void round_vector(std::vector<double>& v)
	{
		for (double& i : v) {
			i = std::round(i);
		}
	}

	//e
	/**
	* @brief: reverses vector in place
	*
	* @param: std::vector<T>& v
	*
	* @return: void
	*/
	template <typename T>
	void reverse(std::vector<T>& v)
	{
		for (unsigned long i = v.size()/2; i > 0; --i) {
			std::swap(v[i-1], v[v.size()-i]);
		}
	}
} /* aufgabe1 */ 

template <typename T>
void printv(std::vector<T> const& v)
{
	std::cout << "v:" << '\n';
	for (auto&& i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

int main(int argc, char** argv)
{
	std::vector<double> v{ 2, 1, 4, 7, 3, -3, 42, 4, 0, 9, 11 };
	std::vector<double> v1{ 0, .1, .2, .3, .4, .5, .6, .7, .8, .9, 1, 1.4, 1.5, 1.6, 2, -1.5 };
	std::vector<double> v2{ 0, 1, 2 };
	std::vector<double> v3{ 0, 1, 2, 3 };
	std::vector<double> v0{};
	auto pair = aufgabe1::minmax(v);
	
	std::cout << "pair:" << '\n';
	std::cout << pair.first << ' ' << pair.second << '\n';

	printv(v);
	aufgabe1::reverse(v);
	printv(v);
	printv(aufgabe1::reversed(v));

	printv(v2);
	aufgabe1::reverse(v2);
	printv(v2);
	printv(aufgabe1::reversed(v2));

	printv(v3);
	aufgabe1::reverse(v3);
	printv(v3);
	printv(aufgabe1::reversed(v3));

	printv(v0);
	aufgabe1::reverse(v0);
	printv(v0);
	printv(aufgabe1::reversed(v0));

	printv(v1);
	aufgabe1::round_vector(v1);
	printv(v1);

	std::cout << '\n';

	return 0;
}
