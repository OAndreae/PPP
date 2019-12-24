// Oliver Andreae 03/01/2019
// 

#include <algorithm>
#include <iostream>
#include <vector>

void pause()
{
	std::cout << "Please enter any charcter to continue...";
	char c;
	std::cin.clear();
	std::cin >> c;
}

int main()
try {
	using namespace std;

	vector<double> temps;			// temperatures
	for (double temp; cin >> temp;)	// read into temp
		temps.push_back(temp);		// put temp into vector

	// compute mean temperature
	double sum = 0;
	for (double x : temps) sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';

	// compute median temperature
	sort(temps.begin(), temps.end());
	cout << "Median temperature: " << temps[temps.size() / 2] << '\n';

	pause();
	return 0;
}
catch (const std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	pause();
	return 1;
}
catch (...) {
	std::cerr << "error: unhandled exception\n";
	pause();
	return 2;
}