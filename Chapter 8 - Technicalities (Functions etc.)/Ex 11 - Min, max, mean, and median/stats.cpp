// Oliver Andreae 14/12/2017
// Solution to PPP2 exercise 8.11
//
// - Calculate the smallest and largest element in a vector
// - Calculate the mean and median

#include "../../std_lib_facilities.h"

using namespace std;

void keep_window_open(char c)
{
	cout << "Please enter " << c << " to exit\n";

	char cc;
	cin.clear();
	while (cin >> cc && cc != c)
		cout << "Please enter " << c << " to exit\n";
}

struct Stats {
	Stats(){ }
	Stats(double s, double l, double m, double med)
		:smallest{s}, largest{l}, mean{m}, median{med}
	{
	}
	double smallest;
	double largest;
	double mean;
	double median;
};

double mean(const vector<double>& v)
{
	double sum = 0.0;
	for (auto& i : v)
		sum += i;
	
	return sum / v.size();
}

double median(const vector<double>& v)
{
	vector<double> v_copy{v};
	sort(v_copy);

	if (v_copy.size() % 2 == 0) {
		size_t mid = v_copy.size() / 2;

		double mid_sum = v_copy[mid] + v_copy[mid + 1];
		double mean = mid_sum / 2; // calculate mean of two middle values
		
		return mean;
	}

	size_t mid = narrow_cast<size_t>(v_copy.size() / 2);
	return v_copy[mid];
}

double smallest(const vector<double>& v)
{
	double d = v.at(0);
	
	for (auto& i : v) // find smallest
		if (i < d)
			d = i;
	
	return d;
}

double largest(const vector<double>& v)
{
	double d = v.at(0);

	for (auto& i : v) // find largest
		if (i > d)
			d = i;

	return d;
}

inline Stats stats(const vector<double>& v)
{
	return Stats {smallest(v), largest(v), mean(v), median(v)};
}

int main()
try {
	vector<double> v;
	for (size_t i = 0; i < 10; i++) {
		v.push_back(i);
	}

	Stats s = stats(v);

	cout << "Smallest: " << s.smallest << '\n';
	cout << "Largest: " << s.largest << '\n';
	cout << "Mean: " << s.mean << '\n';
	cout << "Median: " << s.median << '\n';

	keep_window_open('#');
} catch (const std::exception& e) {
	cout << "error: " << e.what() << '\n';
	keep_window_open('#');
}