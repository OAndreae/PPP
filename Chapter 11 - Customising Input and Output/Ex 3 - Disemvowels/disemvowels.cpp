// Oliver Andreae 6/1/2018
// Solution to PPP exercise 11.3

// Write a program that reads a file and
// outputs all of its words without vowels
//
// e.g.
// "Ask the young gentleman"
// becomes "sk th yng gtlmn"

/*
	open file
	read into string
	remove vowels
		return new string with consonants
		and spaces
	print
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>


/// <summary>
/// prevents the console from closing
/// similar to system("PAUSE")
/// </summary>
void pause()
{
	std::cout << "Please enter a character to continue...";
	std::cin.clear();

	// remove input in buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char ch;
	std::cin.get(ch);
}

std::string consonants(const std::string& s)
{
	std::ostringstream oss;

	// add all non-vowels to oss
	for (const char& c : s) {
		switch (c) {
			// ignore vowels
			case 'a': case 'e': case 'i': case 'o': case 'u':
			case 'A': case 'E': case 'I': case 'O': case 'U':
				break;
			// otherwise add to oss
			default:
				oss << c;
				break;
		}
	}

	return oss.str();
}

bool is_slash(char c)
{
	return c == '//' || c == '\\';
}

std::string file()
{
	std::cout << "Please specify a file path: ";
	std::string file_path;
	std::getline(std::cin, file_path);

	std::ifstream ifs{file_path};
	if (!ifs)
		throw std::runtime_error{"can't open file: " + file_path};

	// copy
	std::ostringstream data;
	for (char c; ifs.get(c);)
		data << c;
	
	

	return data.str();
}

int main()
try {
	std::string cons = consonants(file());

	std::cout << "File without vowels:\n\n"
		<< cons << '\n';
		
	pause();
} catch (const std::exception& e) {
	std::cerr << "Error: " << e.what() << '\n';
	pause();
}