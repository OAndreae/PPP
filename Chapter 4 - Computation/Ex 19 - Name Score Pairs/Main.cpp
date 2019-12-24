/*
	Exercise 19 from Programming Principles and Practice using C++
	Name and value pairs

	Oliver Andreae 26/11/2017
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline void keep_window_open()
{
	cin.clear();
	cout << "\nPlease enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

bool is_unique(const string& name, const vector<string>& name_list)
{
	for (auto& current : name_list)
		if (name == current)
			return false;

	//not in name_list
	return true;
}


int main()
try {
	cout << "Please enter names with a corresponding score. Enter 'NoName 0' to exit.\n";

		vector<string> names;
		vector<int> scores;

		string name;
		int score;

		//read while input is valid
		while (cin >> name >> score && name != "NoName") {
			//validate name
			if (!is_unique(name, names))
				throw runtime_error("duplicate: " + name);
			
			names.push_back(name);
			scores.push_back(score);
		}

		//print names and corresponding scores
		cout << "\nName\tScore\n";
		cout << "------------------\n";
		for (int i = 0; i < names.size(); i++)
			cout << names[i] << "\t\t" << scores[i] << "\n";

		
		keep_window_open();

	} 
catch (const runtime_error& e) {
		cout << e.what();
		keep_window_open();
	}
catch (...) {
		cout << "error occured\nexiting...";
		keep_window_open();
	}
