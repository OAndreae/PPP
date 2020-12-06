#pragma once
#include <string>

	class Patron {
	public:
		Patron();
		Patron(const std::string& name, int card, double fee);

		std::string name() const { return m_name; }
		int card_number() const { return m_card; }
		double fee() const { return m_fee; }

		void set_fee(double fee);
	private:
		std::string m_name; 
		int m_card;
		double m_fee;
	};

	bool owes_fee(const Patron& p);
	bool operator==(const Patron& a, const Patron& b);
