#pragma once
#include <iostream>
namespace Chrono {
	enum class Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	
	class Date {
	public:
		class Invalid{ }; // to throw as an exception

		Date(int d, Month m, int y); // check for valid date and initialise	
		Date(); //default constructor

		// use default copy operations

		//non-modifiying operations
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		//modifying operations
		/// <summary>
		/// add n days
		/// </summary>
		/// <param name="n">days to add</param>
		void add_day(int n);
		/// <summary>
		/// add n months
		/// </summary>
		/// <param name="n">months to add</param>
		void add_month(int n);
		/// <summary>
		/// add n years
		/// </summary>
		/// <param name="n">years to add</param>
		void add_year(int n);
	private:
		int d;
		Month m;
		int y;

	};

	//HELPERS
	bool is_date(int d, Month m, int y);
	bool leap_year(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& d);

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	Day day_of_week(const Date& d); // day of week of d
	Date next_Sunday(const Date& d); // next Sunday after d
	Date next_weekday(const Date& d); // next weekday after d
	int days_in_month(Month m, int year);

}

