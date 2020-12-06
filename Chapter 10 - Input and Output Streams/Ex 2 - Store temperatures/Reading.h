#pragma once
#include <fstream>

struct Reading {
	Reading() : hour{0}, temperature{0.0} {}
	Reading(int h, double t) : hour{h}, temperature{t} {}
	int hour; // hour after midnight [0:23]
	double temperature; // in Fahrenheit
};

std::ostream& operator<<(std::ostream& os, const Reading& r);