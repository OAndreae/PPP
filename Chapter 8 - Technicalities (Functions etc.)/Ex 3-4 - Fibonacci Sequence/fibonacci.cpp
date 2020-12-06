// Oliver Andreae 13/12/2017
// Solution to PPP2 exercise 8.2-4

/*
	Exercise 2: write an output function for vector<int>

	Exercise 3: make a vector<int> containing Fibbonacci numbers,
	e.g. 1, 2, 3, 5, 8, 13, 21, 34
	makes a good test case for exercise 2.

	Exercise 4: find an approximation for the maximum number
	an int can hold
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(string label, vector<int> v)
{
	cout << label << '\n';

	for (size_t i = 0; i < v.size(); i++)
		cout << i << '\t' << v[i] << '\n';
}

/// <summary>
/// Fills a vector with Fibonacci numbers
/// </summary>
/// <param name="x">first number</param>
/// <param name="y">second number</param>
/// <param name="v">vector to fill</param>
/// <param name="n">amount of elements to put in v</param>
void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.reserve(n);
	v.push_back(x);
	v.push_back(y);

	for (size_t i = 1; i < n; i++) {
		int prev = v.at(i - 1);
		int next = prev + v.at(i);
		
		v.push_back(next);
	}
}

int main()
try {
	vector<int> fib_seq;
	fibonacci(4, 5, fib_seq, 100);
	print("Fibonacci Sequence", fib_seq);

	char c;
	cin >> c;

} catch (const std::exception& e) {
	cerr << e.what() << '\n' <<
		"Enter a character to exit\n";
	char c;
	cin >> c;
}
