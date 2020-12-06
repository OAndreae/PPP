// Oliver Andreae, 15/12/2017
// Solution to PPP2 exercises 9.5-9.9
//
/*	
	Library Content Management System
	

*/

#include "Library.h"

#include <iostream>

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
	Library lib;
	Book wotw{"2-6-5-f", "War of the Worlds", "H.G. Wells", 1898, Genre::fiction};
	Book sherlock{"4-2-3-h", "Sherkock Holmes", "Sir Arthur Conan-Doyle", 1898, Genre::fiction};
	Book ns{"3-2-7-k", "New Scientist", "Various", 1956, Genre::periodical};


	lib.add_book(wotw);
	lib.add_book(sherlock);

	Patron oliver{"Oliver Andreae", 1, 0};
	Patron elliot{"Elliot Andreae", 2, 5.00};
	Patron micheal{"Micheal Andreae", 3, 2.50};

	lib.add_patron(oliver);
	lib.add_patron(elliot);
	
	cout << "Indebted Patrons\n";
	for (auto& p : lib.fees_owed())
		cout << p.name() << " owes " << p.fee() << '\n';

	// expected to work
	lib.check_out(Transaction{wotw, oliver, Chrono::Date{16,Chrono::Month::oct,2002}});
	
	// expects errors
	lib.check_out(Transaction{ns, micheal, Chrono::Date{16,Chrono::Month::oct,2002}});
	
	keep_window_open();
} catch (const std::exception& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
}