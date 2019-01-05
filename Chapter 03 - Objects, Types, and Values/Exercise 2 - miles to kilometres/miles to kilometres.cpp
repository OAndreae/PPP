// Oliver Andreae --/--/----

#include <iostream>

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

	double miles = 0;
	while (true) {
		cout << "Please enter the number of miles you wish to convert\n"
			">";
		cin >> miles;
		if (miles > 0)
			break;

		cout << "Value must be positive. Please try again\n";
	}

	double km = miles * 1.609;

	cout << miles << "mi is " << km << "km\n";
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