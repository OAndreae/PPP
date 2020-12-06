#pragma once
#include <fstream>

struct Reading {
	Reading() : hour{0}, temperature{0.0} {}
	Reading(int h, double t) : hour{h}, temperature{t} {}
	int hour; // hour after midnight [0:23]
	double temperature; // in Fahrenheit
};

std::ostream& operator<<(std::ostream& os, const Reading& r);
std::istream& operator>>(std::istream& os, Reading& r);

bool operator==(const Reading& a, const Reading& b);
bool operator!=(const Reading& a, const Reading& b);

static bool sort_by_temp(const Reading & r1, const Reading & r2)
{
	return r1.temperature < r2.temperature;
}
