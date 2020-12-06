// Oliver Andreae 27/1/18
// Solution to PPP2 exercise 11.13

// Reverse the order of words in a file (whitespace separated strings)
// e.g.
// The gentle boy
// ...becomes..
// boy gentle The

#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


/// <summary>
/// prevents the console from closing
/// similar to system("PAUSE")
/// </summary>
void pause()
{
	std::cout << "Please enter a character to continue...";
	std::cin.clear();

	char ch;
	std::cin.get(ch);
}


std::vector<std::string> words(const std::string& file_path)
{
	std::ifstream ofs{file_path};
	if (!ofs)
		throw std::invalid_argument{"failed to open file: " + file_path};
	
	// fill vector
	std::vector<std::string> v;
	while (ofs) {
		std::string s;
		ofs >> s;
		v.push_back(s);
	}

	return v;
}


int main()
try {
	std::vector<std::string> v = words("story.txt");
	
	// print original
	using std::cout;
	cout << "Original order\n\n";
	for (auto& i : v)
		cout << i << '\n';

	std::reverse(v.begin(), v.end());

	// print
	cout << "Reversed order\n\n";
	for (auto& i : v)
		cout << i << '\n';

	pause();
} catch (const std::exception& e) {
	std::cerr << "Error: " << e.what() << '\n';
	pause();
}