// Oliver Andreae 05/01/2019
//
// TASK
// input two integers from the use
// determine the smaller, larger, sum, diffference, product, and ratio of these numbers
// report these results to the user

#include <algorithm>
#include <iostream>
#include <numeric>

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

	cout << "Please enter two real numbers (followed by 'enter')\n"
		">";
	double val1 = 0;
	double val2 = 0;
	cin >> val1 >> val2;

	// print smallest
	cout << "Smallest: " << (val1 < val2 ? val1 : val2) << '\n';

	// print larger
	cout << "Largest: " << (val1 > val2 ? val1 : val2) << '\n';

	// print sum
	cout << "Sum: " << (val1 + val2) << '\n';

	// print difference 
	cout << "Difference: " << abs(val1 - val2) << '\n';

	// print product
	cout << "Product: " << val1*val2 << '\n';

	//print ratio
	cout << "Ratio (val1:val2) : " << val1 << ':' << val2 << '\n';


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