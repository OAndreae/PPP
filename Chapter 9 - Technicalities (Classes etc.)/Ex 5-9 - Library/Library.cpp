#include "Library.h"



	std::vector<Patron> Library::fees_owed()
	{
		std::vector<Patron> debters;

		// calculate who owes fees
		for (auto& p : m_patrons)
			if (owes_fee(p))
				debters.push_back(p);
		
		return debters;
	}

	void Library::add_book(const Book& b)
	{
		m_books.push_back(b);
	}

	void Library::add_patron(const Patron& p)
	{
		m_patrons.push_back(p);
	}

	void Library::check_out(const Transaction& t)
	{
		if (std::find(m_patrons.begin(), m_patrons.end(), t.patron) == m_patrons.end()) {
			// patron not library member
			throw std::logic_error(t.patron.name() + " is not a member of this library");
			return;
		}

		if (std::find(m_books.begin(), m_books.end(), t.book) == m_books.end()) {
			// book not in library
			throw std::logic_error(t.book.isbn() + " does not belong to this library");
			return;
		}

		if (t.patron.fee() > 0) {
			// fees owed
			throw std::logic_error(t.patron.name() + " owes fees");
			return;
		}

		// book is in library & patron is member
		// create transaction and add to transactions
		m_transactions.push_back(t);
	}

	void Library::check_in(const Transaction& t)
	{
		throw std::logic_error("check_in(): not implemented");
	}
