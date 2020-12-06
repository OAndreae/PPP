// Oliver Andreae 17/12/2017
// Solution to chapter 9 drill

#include "Date.h"

#include <iostream>

using namespace Chrono;

using namespace std;

/// <summary>
/// prevent the Windows Console from closing
/// </summary>
void keep_window_open()
{
	char c;
	cin.clear();
	cin >> c;
}

int main()
try {
	Date d{1,Month::jan,2000};
	cout << d;

	keep_window_open();

} catch (const std::exception& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
}