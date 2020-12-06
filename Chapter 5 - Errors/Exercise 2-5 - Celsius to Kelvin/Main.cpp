/*
	Oliver Andreae
	December 2017

	Solution to PPP exercise 5.2
*/

#include <iostream>
#include <vector>

using namespace std;

//required by Windows systems
inline void keep_window_open()
{
	cin.clear();
	cout << "\nPlease enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

//convert Celsius to Kelvin
//c > -273.15 (absolute zero)
double c_to_k(double c)
//pre-conditions: c > -273.15
{
	if (c < -273.15)
		throw logic_error("temperature is less than absolute zero!");

	double k = c + 273.15;
	return k;
}

//convert Kelvin to Celsius
//k > 0 (absolute zero)
double k_to_c(double k)
{
	if (k < 0)
		throw logic_error("temperature is less than absolute zero!");

	double c = k - 273.15;
	return c;
}

int main()
try {
	//read temperature
	double temp = 0;
	char unit = 'C';
	cin >> temp >> unit;
	
	//convert temperature appropriately
	if (unit == 'C' || unit == 'c') {
		double k = c_to_k(temp);
		cout << k << "K\n";
	} else if (unit == 'K' || unit == 'k') {
		double c = k_to_c(temp);
		cout << c << "C\n";
	} else
		cerr << "invalid unit\n";

	keep_window_open();

	return 0;
}
catch (logic_error& e) {
	cout<< "error:" << e.what();
	keep_window_open();
	return 1;
}

//original
//
//double ctok(double c)
//{
//	int k = c + 273.15;
//	return int;
//}
//
//int main()
//{
//	double c = 0;
//	cin >> d;
//	double k = ctok("c");
//	Cout << k << '\n';
//}