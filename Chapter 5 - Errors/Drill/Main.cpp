#include <iostream>
#include <vector>

using namespace std;

//required by Windows systems
inline void keep_window_open()
{
	cin.clear();
	cout << "\nPlease enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

int main()
try {
	//<code snippet>
	cout << "Success!\n";
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << "\n";
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

//CODE SNIPPETS

//Cout << "Success!\n";
//cout << "Success!\n;
//cout << "Success" << !\n"
//cout << success << '\n';
//string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n!;
//vector<int> v(10); v(5) = 7; if(v(5)!=7) cout << "Success!\n!";
//if(cond) cout << "Success!\n"; else cout << "Fail!\n";
//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
//string s = "ape"; boo c = "fool"<s;  if(c) cout << "Success!\n"
//string s = "ape"; if(s == "fool") cout << "Success!\n"
//string s = "ape"; if (s=="fool") cout < "Success!\n";
//string s = "ape"; if (s+"fool") cout < "Success!\n";
