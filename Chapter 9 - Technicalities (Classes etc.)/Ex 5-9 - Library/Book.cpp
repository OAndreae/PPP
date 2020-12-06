#include "Book.h"

#include <string>

using namespace std;

	// member function definitions

	Book::Book(const std::string& isbn, const std::string& title, const std::string& author, int copyright, Genre genre)
		:m_isbn{isbn},
		m_title{title}, 
		m_author{author}, 
		m_copyright{copyright},
		m_genre{genre}
	{
		if (!is_isbn(isbn))
			throw Invalid::exception{string{"invalid ISBN: " + isbn}.c_str()};
	}

	const Book& default_book()
	{
		const static Book b{"1-2-3-a", "Default Book", "Default Author", 2017, Genre::fiction};
		return b;
	}

	Book::Book()
		:m_isbn{default_book().isbn()},
		m_title{default_book().title()},
		m_author{default_book().author()},
		m_copyright{default_book().copyright_date()}
	{
	}	

	// helper functions

	bool is_isbn(const std::string& isbn)
	// valid ISBN is in form "n-n-n-x"
	// where n is integer
	// and x is a digit or letter
	{
		if (isbn.size() > 7) return false;
		
		if (!isdigit(isbn[0])    // number
			|| isbn[1] != '-'
			|| !isdigit(isbn[2]) // number
			|| isbn[3] != '-'
			|| !isdigit(isbn[4]) // number
			|| isbn[5] != '-'
			|| !isalnum(isbn[6]) // letter or number
			) return false;

		return true;
	}

	bool operator==(const Book& a, const Book& b)
	{
		return a.isbn() == b.isbn();
	}

	bool operator!=(const Book& a, const Book& b)
	{
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& os, const Book& b)
	{
		return os << b.title() << '\n'
			<< b.author() << '\n'
			<< b.isbn();
	}
