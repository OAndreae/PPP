#include "Reading.h"

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
	return os << r.hour << ' ' << r.temperature;
}

std::istream& operator>>(std::istream& is, Reading& r)
{
	// throw for bad()
	is.exceptions(is.exceptions() | std::ios_base::badbit);

	// read hour
	int h;
	if (!(is >> h)) {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	// read temp
	double t;
	if (!(is >> t)) {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	// reading succeeded
	r.hour = h;
	r.temperature = t;
	return is;
}

bool operator==(const Reading & a, const Reading & b)
{
	return a.hour == b.hour
		&& a.temperature == b.temperature;
}

bool operator!=(const Reading & a, const Reading & b)
{
	return !(a == b);
}

