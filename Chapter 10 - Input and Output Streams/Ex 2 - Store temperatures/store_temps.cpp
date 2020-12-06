// Oliver Andreae 1/1/2018
// Solution to PPP2 chapter 10 exercise 2

/*
	- Create a file of temperature readings in (hour temperature) pairs 
		e.g. 
		0 65.3
		1 68.5
	- For testing, fill the file with at least 50 "temperature readings"		
*/

#include "Reading.h"

#include <iostream>
#include <fstream>
#include <random>

void keep_window_open()
{
	std::cout << "Please enter a character to exit...";

	std::cin.clear();
	char ch;
	std::cin.get(ch);
}


double rand_temp(double min, double max)
{
	std::random_device rd;
	std::default_random_engine gen{rd()};
	std::uniform_real_distribution<double> dist(min, max);
	return dist(gen);
}

int rand_hour()
{
	std::random_device rd;
	std::default_random_engine gen{rd()};
	std::uniform_int_distribution<int> dist{0, 23};
	return dist(gen);
}

int main()
{
	std::ofstream os{"raw_temps.txt"};

	for (size_t i = 0; i < 50; i++) {
		Reading r{rand_hour(), rand_temp(0,120)};
		os << r << '\n';
	}
	
	keep_window_open();
}