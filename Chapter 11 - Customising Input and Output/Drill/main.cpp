// Oliver Andreae 2/1/2018
// Solution to PPP2 chapter 11 drill

#include <iostream>
#include <iomanip> // useful formating functions
#include <vector>
#include <string>

void pause()
{
	std::cout << "Please enter a character to continue...";
	std::cin.clear();
	char ch;
	std::cin >> ch;
}

void birth()
{
	int birth_year = 2002;

	using std::cout;
	cout << std::showbase
		<< birth_year << "\t(decimal)\n"
		<< std::hex << birth_year << "\t(hexadecimal)\n"
		<< std::oct << birth_year << "\t(octal)\n";

	int age = 15;
	cout << '\n' << std::dec << age << "\t(age)\n";
}

void bases()
{
	using std::cout;
	cout << "Please enter four numbers: ";
	int a, b, c, d;

	using std::cin;
	cin >> a >> std::oct >> b >> std::hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}

void precision()
{
	double num = 1234567.89;
	std::cout << num << "\t(defaultfloat)\n"
		<< std::fixed << num << "\t(fixed)\n"
		<< std::scientific << num << "\t(scientific)\n";
}

struct Contact {
	Contact() :first_name{"John"}, last_name{"Smith"}, telephone{"01234 567890"}, email{"johnsmith@provider.com"} {};
	Contact(std::string f, std::string l, std::string t, std::string e) :first_name{f}, last_name{l}, telephone{t}, email{e} {};

	std::string first_name;
	std::string last_name;
	std::string telephone;
	std::string email;
};

void table_width()
{
	using std::vector;
	vector<Contact> contacts{
	Contact{"Oliver", "Andreae", "07721 180105", "oliverandreae@outlook.com"},
	Contact{"Elliot", "Andreae", "07151 184802", "longdrop60@icloud.com"}
	};

	for (auto& c : contacts) {
		using std::setw;
		std::cout << std::left << setw(10) << c.last_name
			<< setw(10) << c.first_name
			<< setw(13) << c.telephone
			<< setw(30) << c.email << '\n';
	}
}
int main()
{
	birth();
	bases();
	precision();
	table_width();

	pause();
}