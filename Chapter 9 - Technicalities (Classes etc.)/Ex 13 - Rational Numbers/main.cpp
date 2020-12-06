// Oliver Andreae 27/12/2017
// Solution to PPP2 chapter 9, exercise 13
// 
// Implement a rational number class
// with + - * / == != operations

#include "Rational.h"

#include <iostream>

void keep_window_open()
{
	char c;
	std::cin.clear();
	std::cin >> c;
}

int main()
{
	using namespace Numerics;

	Rational r1{1,2};
	Rational r2{1,4};

	using std::cout;

	cout << r1 << " + " << r2 << " = " << r1 + r2 << '\n';
	cout << r1 << " - " << r2 << " = " << r1 - r2 << '\n';
	cout << r1 << " * " << r2 << " = " << r1 * r2 << '\n';
	cout << r1 << " / " << r2 << " = " << r1 / r2 << '\n';

	Rational r3;
	cout << "default Rational: " << r3 << '\n';

	Rational r4{100,10};
	cout << "100/10 = " << r4 << '\n';

	keep_window_open();
}