#include "Rational.h"

#include <stdexcept>
#include <string>

namespace Numerics {
	void simplify(Rational& r);

	Rational::Rational()
		: m_num{1}, m_denom{1}
	{
		simplify(*this);
	}

	Rational::Rational(int n, int d)
		: m_num{n}, m_denom{d}
	{
		simplify(*this);
	}

	// helper functions
	
	// find the highest common factors
	int hcf(int a, int b)
	{
		// calculate using positive arguments
		a = a < 0?std::abs(a):a;
		b = b < 0?std::abs(b):b;

		int low = a < b?a:b;
		int high = a > b?a:b;

		// find factors of lowest, starting from lowest
		// return first common factor (HCF)
		// 1 is the minimum HCF any numbers
		for (int f = low; f > 0; --f)
			if (high%f == 0 && low%f == 0) // f is a factor of high and low
				return f;
	}

	// find the lowest common multiple
	int lcm(int a, int b)
	{
		return (a * b) / hcf(a, b);
	}

	// simplify rational
	void simplify(Rational& r)
	{
		//highest common factor
		int h = hcf(r.numerator(), r.denominator());
		// already simplified
		// prevents endless pointer recursion
		if (h == 1)
			return;
		
		r = Rational{r.numerator() / h, r.denominator() / h};
	}

	// arithmetic operators
	Rational operator+(const Rational& l, const Rational& r)
	{
		//int common = lcm(l.denominator(), r.denominator());
		//int l_num = 

		// find common denominator
		int common_denom = l.denominator() * r.denominator();
		
		// calculate the new numerators
		int l_num = l.numerator() * r.denominator();
		int r_num = r.numerator() * l.denominator();

		int sum_num = l_num + r_num;

		Rational sum{sum_num, common_denom};
		simplify(sum);
		return sum;
	}

	Rational operator-(const Rational& l, const Rational& r)
	{
		// find common denominator
		int common_denom = l.denominator() * r.denominator();

		// calculate the new numerators
		int l_num = l.numerator() * r.denominator();
		int r_num = r.numerator() * l.denominator();

		int diff_num = l_num - r_num;

		Rational diff{diff_num, common_denom};
		simplify(diff);

		return diff;
	}

	Rational recipricol(const Rational& r)
	{
		return Rational{r.denominator(), r.numerator()};
	}

	Rational operator/(const Rational& l, const Rational& r)
	{
		// keep, change, flip
		// keep left; change sign (*); flip right

		Rational r_rec = recipricol(r);
		return l * r_rec;
	}

	Rational operator*(const Rational& l, const Rational& r)
	{
		int num = l.numerator() * r.numerator();
		int denom = l.denominator() * r.denominator();
		
		Rational rat{num, denom};
		simplify(rat);
		
		return rat;
	}

	// equality operators
	bool operator==(const Rational& a, const Rational& b)
	{
		return a.numerator() == b.numerator()
			&& a.denominator() == b.denominator();
	}

	bool operator!=(const Rational& a, const Rational& b)
	{
		return !(a == b);
	}


	std::ostream& operator<<(std::ostream& os, const Rational& r)
	{
		// omit "x/1"
		if (r.denominator() == 1)
			return os << r.numerator();
		
		return os << r.numerator() << '/' << r.denominator();
	}
}