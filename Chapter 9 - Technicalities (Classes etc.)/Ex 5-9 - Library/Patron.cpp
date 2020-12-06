#include "Patron.h"
#include <exception>

	//member functions

	Patron::Patron(const std::string & name, int card, double fee = 0)
		: m_name{name}, m_card{card}, m_fee{fee}
	{
	}

	const Patron& default_patron()
	{
		const static Patron dp{"John Smith", 123};
		return dp;
	}

	Patron::Patron()
	{
	}

	void Patron::set_fee(double fee)
	{
		if (fee < 0)
			throw std::invalid_argument{"negative fee"};
		else
			m_fee = fee;
	}

	// helper functions
	bool owes_fee(const Patron & p)
	{
		return p.fee() > 0;
	}

	bool operator==(const Patron & a, const Patron & b)
	{
		return a.card_number() == b.card_number();
	}
