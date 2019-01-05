#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	//salutation
	cout << "Please enter the name of the person you wish to write to (followed by 'enter'):\n";
	string first_name;
	cin >> first_name;

	cout << "Dear " << first_name << ",\n"
		"\tWe are all fine, and I hope that you're keeping well too.\n";

	//friend gossip
	cout << "Please enter the name of another friend: \n";
	string friend_name;
	cin >> friend_name;

	cout << "Have you seen " << friend_name << " recently?\n";

	//male or female
	cout << "Is your friend male (m) or female (f)?\n";
	char friend_sex;
	cin >> friend_sex;

	//gender specific message
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	else if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";
	else
		//default generic pronoun
		cout << "If you see " << friend_name << " please ask them to call me.\n";

	//happy birthday
	cout << "How old is your friend (in years)?\n";
	int age;
	cin >> age;

	if (age < 0 || age > 110)
		throw runtime_error("You're kidding!");
	else if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age > 70)
		cout << "I hope you are enjoying your retirement.\n";

	//closing statement
	cout << "Yours sincerley,\n\n\n"
		"Oliver Andreae\n\n";

	cin.clear();
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}// Drill from chapter 3 PPP2
// incomplete as previously completed in another file
#include <iostream>
#include <string>
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

	cout << "Please enter your first name (followed 'enter'):\n";
	string first_name;
	cin >> first_name;
	cout << "Hello, " << first_name << "!\n";
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