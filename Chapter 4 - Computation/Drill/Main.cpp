#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

double to_metres(double value, const string& unit)
{
	//common conversion factors
	constexpr double cm_per_metre = 100.0;
	constexpr double cm_per_inch = 2.54;
	constexpr double inches_per_ft = 12;

	constexpr double inches_per_metre = cm_per_metre / cm_per_inch;
	constexpr double ft_per_metre = inches_per_metre / inches_per_ft;


	//determine unit
	if (unit == "m")
		return value;
	else if (unit == "cm")
		return value / cm_per_metre;
	else if (unit == "in")
		return value / inches_per_metre;
	else if (unit == "ft")
		return value / ft_per_metre;
	else
		throw invalid_argument("invalid unit");
}

double total(const vector<double>& v)
{
	double sum = 0;
	for (auto& i : v)
		sum += i;

	return sum;
}

void print_values(const vector<double>& v)
{
	for (auto& i : v) {
		cout << i << endl;
	}
}

int main()
{

	//minimum value in metres
	double min = 100000000;

	//maximum value in metres
	double max = -100000000;

	//prompt
	cout << "Please enter a number and a unit. Enter '|' to exit.\n";
	double num = 0;
	string unit = "";

	vector<double> values;

	//read the number and unit while the input is valid
	while (cin >> num >> unit) {

		//add the length in metres
		double length = to_metres(num, unit);
		values.push_back(length);

		//compate to largest/smallest value
		if (length < min) {
			cout << "the smallest number so far\n";
			min = length;
		}

		if (length > max) {
			cout << "the greatest number so far\n";
			max = length;
		}
	}

	//output data
	cout << min << " was the smallest value entered\n";
	cout << max << " was the greatest value entered\n";
	cout << values.size() << " were values entered\n";
	cout << total(values) << " was the sum of values entered\n";

	cout << "You entered:\n";
	sort(values.begin(), values.end());
	print_values(values);

	keep_window_open();
}