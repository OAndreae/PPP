// Oliver Andreae 1/1/2018
// Solution to PPP2 chapter 10 exercise 3

/*
	- Read temperatures from raw_temps.txt (see exercise 2)
		into a vector of Readings
	- Calculate the mean and median temperatures
*/

#include "Reading.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void keep_window_open()
{
	std::cout << "Please enter a character to exit...";

	std::cin.clear();
	char ch;
	std::cin.get(ch);
}

void end_of_loop(std::istream& is, char term, const std::string& msg)
{
	if (is.fail()) {
		is.clear();
		char ch = ' ';
		if (is >> ch && ch == term) return; // all is fine
		throw std::runtime_error{msg};
	}
}

void read_temps(std::vector<Reading>& v, const std::string& file)
{
	std::ifstream ifs{file};
	if (!ifs) throw std::invalid_argument{file + "is invalid"};

	while (true) {
		Reading r; // newly initialised Reading each time around
		if (!(ifs >> r)) break;
		v.push_back(r);
	}
	end_of_loop(ifs, '|', "error reading " + file);
}

double mean(const std::vector<Reading>& v)
{
	double sum = 0;
	for (auto& i : v)
		sum += i.temperature;
	
	return sum / v.size();
}


double median(const std::vector<Reading>& v)
{
	std::vector<Reading> v2 = v;

	// ordered
	std::sort(v2.begin(), v2.end(), sort_by_temp);

	if (v2.size() % 2 == 0) {
		double t1 = v2[v2.size() / 2].temperature;
		double t2 = v2[(v2.size() / 2) + 1].temperature;

		// mean of t1 and t2
		return (t1 + t2) / 2;
	}
	else
		return v2[v2.size() / 2].temperature;	
}

int main()
{
	std::vector<Reading> readings;

	read_temps(readings, "raw_temps.txt");

	std::cout << "Mean: " << mean(readings) << '\n'
		<< "Median: " << median(readings) << '\n';

	keep_window_open();
}