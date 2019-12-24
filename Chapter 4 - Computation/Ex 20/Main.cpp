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

//print names and corresponding scores
void print_names(const vector<string>& names, const vector<int>& scores)
{
	if (names.size() != scores.size())
		throw invalid_argument("differing amount of names or scores");
	else {
		//print names and scores in a table
		cout << "\nName\t\tScore\n"
			<< "----\t\t-----\n";
		for (int i = 0; i < names.size(); i++)
			cout << names[i] << "\t\t" << scores[i] << "\n";
	}
}

//print the score of the name
void print_score(const string& name, const vector<string> names, const vector<int> scores)
{
	if (names.size() != scores.size())
		throw invalid_argument("differing amount of names or scores");

	if (int i = find(names.begin(), names.end(), name) != names.end()) {
		cout << name << "\t\t" << scores.at(i) << endl;
	} else
		cout << "name not found!\n";
}

int main()
try {

	cout << "Please enter a command:\n"
		"\tadd -name -score\n"
		"\tfind -name\n"
		"\tprint\n"
		"\tquit\n";

		
	vector<string> names;
	vector<int> scores;

	string command;
	while (cin >> command && command != "quit") {
		//no args
		if (command == "quit")
			break;

		//execute commands
		if (command == "add") {
			string name;
			int score;

			if (!(cin >> name >> score))
				throw runtime_error("invalid input\n");

			//validate name
			if (!is_unique(name, names))
				throw runtime_error("duplicate: " + name);

			//add name and score
			names.push_back(name);
			scores.push_back(score);
		} else if (command == "find") {
			//get name
			string name;
			cin >> name;
			
			print_score(name, names, scores);
		} else if (command == "print")
			print_names(names, scores);		
		else
			cout << "command '" << command << "'" << " is not a valid command\n";
	}
		
	keep_window_open();

} catch (const runtime_error& e) {
	cout << e.what();
	keep_window_open();
}
catch (...) {
	cout << "error occured\nexiting...";
	keep_window_open();
}