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

	cout << "Hello, World!";
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