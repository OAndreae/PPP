// Oliver Andreae 13/12/2017
// Solution to PPP2 exercise 8.7-8

/*
	Exercise 7: 
	- Read five names into a vector, then five ages
	- Print (name, age) pairs
	- Sort names vector lexicographically
	- Print (name, age) pairs, ensuring 
		that the name and age match the original

	Exercise 8
	- allow an arbituary number of names
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/// <summary>
/// Prints all names with corresponding ages
/// n.size() == a.size()
/// </summary>
/// <param name="n">names</param>
/// <param name="a">ages</param>
void write_pairs(const vector<string>& n, const vector<int>& a)
{
	if (n.size() != a.size())
		throw invalid_argument("print: n.size() != a.size()");
	
	for (size_t i = 0; i < n.size(); i++)
		cout << n[i] << " is " << a[i] << '\n';
}

void read_pair(string& name, int& age)
{	
	char c;
	while (cin.get(c) && !isdigit(c)) // read full names (e.g. "Oliver Andreae")
		name += c;

	cin.putback(c); // replace first age digit
	cin >> age; // re-read as age
}

void read_pairs(char stop, vector<string>& names, vector<int>& ages)
{
	char c;
	while (cin >> c && c != stop) {
		cin.putback(c);

		string s;
		int n;
		read_pair(s, n);
		
		names.push_back(s);
		ages.push_back(n);
	}
}

size_t find_index(const vector<string>& v, const string& n)
{
	for (size_t i = 0; i < v.size(); ++i) 
		if (v[i] == n)
			return i;

	throw runtime_error("name " + n + " not found in v");
	return -1;
}

void sort_pairs(vector<string>& names, vector<int>& ages)
{
	//original n order
	const vector<string> original_names{names};

	sort(names.begin(), names.end());

	vector<int> original_ages = ages;
	ages.clear();

	for (size_t i = 0; i < original_names.size(); i++) {
		size_t old_pos = find_index(original_names, names[i]); // get original position

		int age = original_ages.at(old_pos); // obtain age
		ages.push_back(age); // add to sorted vector
	}
}

int main()
try {
	const char stop = '#';

	cout << "Please enter (name, age) pairs (e.g. Oliver Andreae 15)\n"
		"Enter " << stop << " to stop:\n";
	
	vector<string> names;
	vector<int> ages;
	read_pairs(stop, names, ages);

	cout << "Original pairs\n";
	write_pairs(names, ages);

	sort_pairs(names, ages);

	cout << "\nSorted pairs\n";
	write_pairs(names, ages);

	//cout << "How many records do you wish to input?\n";
	//int n;
	//cin >> n;
	//
	//// names
	//cout << "Please enter 5 names:\n";
	//vector<string> name;
	//name.reserve(n);
	//name = names(n);
	//
	//// ages
	//cout << "Please enter the ages of the five people:\n";
	//vector<int> age;
	//age.reserve(n);
	//age = ages(n);
	//
	//// print in order entered
	//write_pairs(name, age);
	//
	//sort_pairs(name, age);
	//
	//// print the lexicographically sorted (name, age) pairs 
	//cout << "\nSorted\n";
	//write_pairs(name, age);

	char c;
	cin >> c;

} catch (const exception& e) {
	cout << "Error: " << e.what();

	char c;	// suspend close
	cin >> c;
}
