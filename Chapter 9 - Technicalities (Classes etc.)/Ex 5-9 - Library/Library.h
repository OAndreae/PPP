#pragma once
#include "Book.h"
#include "Date.h"
#include "Patron.h"

#include <vector>
	struct Transaction {
		Transaction(const Book& b, const Patron& p, const Chrono::Date& d)
			:book{b}, patron{p}, date{d}
		{
		}
		Book book;
		Patron patron;
		Chrono::Date date;
	};

	class Library {
	public:
		Library(){}
		Library(const std::vector<Book>& b, const std::vector<Patron>& p)
			: m_books{b}, m_patrons{p}
		{
		}

		std::vector<Patron> fees_owed();

		void add_book(const Book& b);
		void add_patron(const Patron& p);
		void check_out(const Transaction& t);
		void check_in(const Transaction& t);
	private:
		std::vector<Book> m_books;
		std::vector<Patron> m_patrons;
		std::vector<Transaction> m_transactions;
	};

