# include <iostream>
# include <vector>
# include <utility>
# include <cmath>

// Aufgabe 1b)
std::pair<double,double> min_max(std::vector<double> & v)
{
	double min, max = v[0];
	
	for (double entry:v)
		if(entry > max)
		{
			max = entry;
			}
		else if(entry < min)
		{
			min = entry;
			}
	return std::make_pair(min, max);
	}

// Aufgabe 1c)
std::vector<double> reversed(const std::vector<double> & v)
{
	int size = v.size();
	std::vector<double> v_reversed;
	
	while(v_reversed.size() < v.size())
	{
		for (int i = 0; i < size; ++i)
			if (i == size-1)
			{
				v_reversed.push_back(v[i]);
				}
		size -= 1;
	}
	return v_reversed;
}

// Aufgabe 1d)
std::vector<double> round(std::vector<double> & v)
{
	for (int i = 0; i < v.size(); ++i)
		{
			v[i] = std::round(v[i]);
			}
	return v;
	}

//Aufgabe 1e)
std::vector<double> v_swap(std::vector<double> & v)
{
	int size = v.size();
	for (int i = 0; i < v.size()/2; ++i)
		{
			std::swap(v[i], v[size-1]);
			size -= 1;
			}
	return v;
	}

int main(int argc, char** argv)
{
	std::vector<double> v1;
	std::vector<double> v2(2);
	std::vector<double> v3 = {{1.2,2.3,3.4,4.5,5.6,6.7,7.8}};
	
	//Aufgabe 1a)
	std::cout << "Inhalt v1: " << "\n";
	 for (double entry:v1)
		std::cout << "Inhalt v1: " << entry << std::endl;
	std::cout << "Inhalt v2: " << "\n";
	 for (double entry:v2)
		std::cout << entry << std::endl;	
	std::cout << "Inhalt v3: " << "\n";
	 for (double entry:v3)
		std::cout << entry << std::endl;
		
	//Aufgabe 1b)
	std::cout << "min: " << min_max(v3).first << "\n"
	 "max: " << min_max(v3).second << std::endl;
	
	//Aufgabe 1c)
	std::cout << "reversed vector: " << "\n";
	for (double entry:reversed(v3))
		std::cout << entry << std::endl;	
	
	//Aufgabe 1d)
	std::cout << "rounded vector: " << "\n";
	for (double entry:round(v3))
		std::cout << entry << std::endl;
	
	//Aufgabe 1e)
	std::cout << "reversed vector (with swap): " << "\n";
	for (double entry:v_swap(v3))
		std::cout << entry << std::endl;
		
	}
