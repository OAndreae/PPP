#include "Date.h"

#include <array>

using namespace Chrono;

using namespace std;

Chrono::Date::Date(int dd, Month mm, int yy)
	:d{dd}, m{mm}, y{yy}
{
	if (!is_date(dd, mm, yy)) throw Invalid{};
}

const Date& default_date()
{
	static Date dd{1,Month::jan,2001};
	return dd;
}

Chrono::Date::Date()
	:d{default_date().day()},
	m{default_date().month()},
	y{default_date().year()}
{
}

// add n days
void Chrono::Date::add_day(int n)
{
	throw runtime_error("not implemented");
	//while (n<days_in_month(m,y)) {
	//	n -= days_in_month(m, y);
	//	add_month(1);
	//}
}

// add n months
void Chrono::Date::add_month(int n)
{
	throw runtime_error("not implemented");
	
	/*//CHECK

	for (int i = 0; i<n; ++i) {
		Month month = i>12?Month(i%12):Month(i);

		if (month==Month::dec) {
			m = Month::jan; // new year
			add_year(1);
		}
	}

	while (n<days_in_month(m, y)) {
		n -= days_in_month(m, y);

		if (m==Month::dec) {
			m = Month::jan; // reset calender
			add_year(1);
		}

		m = Month(int(m)+1);
	}*/
}

// add n years
void Chrono::Date::add_year(int n)
{
	if (m==Month::feb && d==29 && !leap_year(y+n)) { // beaware of leap years!
		m = Month::mar; // use March 1 instead of February 29
		d = 1;
	}
	y += n;
}

// helper functions:


bool Chrono::is_date(int d, Month m, int y)
{
	if (d<=0) // d must be positive
		return false;

	if (m<Month::jan||Month::dec<m) // invalid month
		return false; //dfs

	if (d>days_in_month(m, y))
		return false;

	return true; // all checks passed
}

bool Chrono::leap_year(int y)
// conditions for leap year:
// y is divisible by 400, or
// y is divisible by 4, but y is not divisible by 100
{
	if (y%400==0)
		return true; // divisible by 400
	else if (y%4==0&&y%100!=0)
		return true; // y is divisible by 4, but not 100

	return false; // normal year
}

bool Chrono::operator==(const Date& a, const Date& b)
{
	return a.day()==b.day()
		&&a.month()==b.month()
		&&a.year()==b.year();
}

bool Chrono::operator!=(const Date& a, const Date& b)
{
	return !(a==b);
}

std::ostream& Chrono::operator<<(std::ostream& os, const Date& d)
{
	return os<<d.day()<<'/'<<int(d.month())<<'/'<<d.year();
}

std::istream& Chrono::operator>>(std::istream& is, Date& dd)
{
	int d, m, y;
	char c1, c2;
	is>>d>>c1>>m>>c2>>y;
	if (!is)
		return is;

	if (c1!='/'||c2!='/') {    // format error
		is.clear(ios_base::failbit); // set the fail bit
		return is;
	}

	dd = Date(d, Month(m), y);       // update dd

	return is;
}

int Chrono::days_in_month(Month m, int year)
{
	int days = 31; // most months have 31 days

	switch (m) {
		case Month::feb:
			days = (Chrono::leap_year(year))?29:28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days = 30;
			break;
	}

	return days;
}

Day Chrono::day_of_week(const Date& d)
//
{
	//const std::array<Month, 12> months{Month::jan, Month::feb, Month::mar, Month::apr, Month::may, Month::jun, 
	//	Month::jul, Month::aug, Month::sep, Month::oct, Month::nov, Month::dec};

	// days since start of year
	int days_passed = 0;
	for (int i = int(Month::jan); i < int(d.month()); i++) // accumulate days elapsed since start of year
		days_passed += days_in_month(Month(i), d.year());

	days_passed += d.day(); // add days in current month

	Day day = Day(days_passed%7); // find current day

	return day;
}

Date Chrono::next_Sunday(const Date& d)
{

	Date next_sun = d;

	for (int i = 0; i<7; ++i) {
		next_sun.add_day(7);
	}
	return next_sun;
}

Date Chrono::next_weekday(const Date& d)
{
	return Date();
}