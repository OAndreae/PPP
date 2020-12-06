// Rational number class
/*
	Rational number: 
	stores number as two parts (numerator and denominator)
	e.g. 5/6 (five sixths)

	Provide:
	- assignment
	- addition
	- subtration
	- multiplication
	- division
	- equality operators
*/
#pragma once
#include <ostream>

namespace Numerics {
	class Rational {
	public:
		Rational();

		/// <summary>
		/// create a rational number from a numerator and denominator
		/// </summary>
		/// <param name="n">numerator</param>
		/// <param name="d">denominator</param>
		Rational(int n, int d);

		int numerator() const { return m_num; }
		int denominator() const { return m_denom; }
	private:
		int m_num;
		int m_denom;
	};

	// helper functions

	// arithmetic operators
	Rational operator+(const Rational& l, const Rational& r);
	Rational operator-(const Rational& l, const Rational& r);
	Rational operator/(const Rational& l, const Rational& r);
	Rational operator*(const Rational& l, const Rational& r);

	// equality operators
	bool operator==(const Rational& a, const Rational& b);
	bool operator!=(const Rational& a, const Rational& b);

	// output operators
	std::ostream& operator<<(std::ostream& os, const Rational& r);
}

