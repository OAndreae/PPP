#pragma once
#include <ostream>
#include <string>
#include <exception>

	
	enum class Genre {
		fiction, nonfiction, periodical, biography, children
	};

	class Book {
	public:
		class Invalid : public std::exception { };
		Book();
		Book(const std::string& isbn, const std::string& title, const std::string& author, int copyright, Genre genre);

		std::string isbn() const { return m_isbn; }
		std::string title() const { return m_title; }
		std::string author() const { return m_author; }
		int copyright_date() const { return m_copyright; }

	private:
		std::string m_isbn;
		std::string m_title;
		std::string m_author;
		int m_copyright;
		Genre m_genre;
	};

	// helper functions
	
	bool is_isbn(const std::string& isbn);

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	std::ostream& operator<<(std::ostream& os, const Book& b);


