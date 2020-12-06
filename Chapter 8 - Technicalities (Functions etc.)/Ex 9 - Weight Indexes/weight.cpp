// Oliver Andreae 14/12/2017
// Solution to PPP exercise 8.9

/*
	Weight Index Calculator
	- Write a function to calculate a weight index 
	  for two given vectors, weight and price
	- Index = sum of all weight[i] * price[i]
	- Ensure that weight.size() == price.sizer()
*/

#include <iostream>
#include <vector>

using namespace std;

void keep_window_open(char c)
{
	cout << "Please enter " << c << " to exit\n";

	char cc;
	cin.clear();
	while (cin >> cc && cc != c)
		cout << "Please enter " << c << " to exit\n";
}

/// <summary>
/// calculate a weight-price index
/// </summary>
/// <param name="w">weights</param>
/// <param name="p">prices</param>
/// <returns>sum of all w[i]*p[i]</returns>
double compute_index(const vector<double> w, const vector<double> p)
{
	if (w.size() != p.size())
		throw invalid_argument("compute_index: w.size() != p.size()");

	double sum = 0.0;
	for (size_t i = 0; i < w.size(); ++i)
		sum += p[i] * w[i];

	return sum;
}

/// <summary>
/// read (weight, price) pairs into vectors
/// </summary>
/// <param name="quit">quit code character to end input</param>
/// <param name="weights">weights vector</param>
/// <param name="prices">prices vector</param>
void read_pairs(char quit, vector<double>& weights, vector<double>& prices)
{
	cout << "> "; // prompt

	char c;
	while (cin >> c && c != quit) {
		cin.putback(c); // not exit character; putback and re-read

		double w = 0.0;
		double p = 0.0;
		cin >> w >> p; // read weight and price

		weights.push_back(w);
		prices.push_back(p);

		cout << "> "; // prompt
	}
}

constexpr char quit = '#';

int main()
try {


	cout << "Please enter your items in (weight, price) pairs.\n"
		"Enter " << quit << " to when you have finished.\n";

	vector<double> prices;
	vector<double> weights;
	read_pairs(quit, weights, prices);

	cout << "Price-weight index: " << compute_index(weights, prices) << '\n';

	
	keep_window_open(quit);
} catch (const invalid_argument& e) {
	cout << "invalid argument: " << e.what() << '\n';
	keep_window_open(quit);
} catch (const exception& e) {
	cout << "error: " << e.what() << '\n';
	keep_window_open(quit);
} 