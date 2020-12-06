/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "..\..\std_lib_facilities.h"

// type of input and value
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch)
	{
	}
	Token(char ch, double val) :kind(ch), value(val)
	{
	}
	Token(char ch, const string& n) :kind{ch}, name{n}
	{
	}
};

// handles input of tokens
// input from cin
class Token_stream {
public:
	Token_stream() :full{false}, buffer{0}
	{
	}

	// get next token
	Token get();

	// put current token in buffer
	void putback(Token t)
	{
		buffer = t; 
		full = true;
	}

	void ignore(char); // discard input upto, and including, c
private:
	bool full{ false };
	Token buffer;
};

const char let = 'L';
const string declkey = "let";
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

// get next token from cin
Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;
	switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case print:
		case '=':
			return Token{ch};
		case '.':
		case '0': case '1':	case '2': case '3':	case '4': 
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val; //re-read as double
			return Token{number, val};
		}
		default:
			if (isalpha(ch)) {
				string s; // name of variable
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				cin.putback(ch); //name finished, putback next token
				if (s == declkey) return Token(let);
				return Token(name, s);
			}
			error("Bad token");
	}
}

// c represents the kind of token
void Token_stream::ignore(char c)
{
	// first look in buffer
	if (full && c == buffer.kind) {
		full = false;
		return;
	}

	full = false;

	// now search input
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

// stored name and value
struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v)
	{
	}
};

vector<Variable> var_table;

// return value from variable named s
double get_value(string s)
{
	for (auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

// set the Variable named s to d
void set_value(string s, double d)
{
	for (auto& v : var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (auto& v : var_table)
		if (v.name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
		}
		case number:
			return t.value;
		case '-':
			return - primary(); //unary negation
		case '+':
			return primary();
		case name:
			return get_value(t.name);
		default:
			error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
			case '*':
				left *= primary();
				return left;
			case '/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				return left;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
			case '+':
				left += term();
				return left;
			case '-':
				left -= term();
				return left;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double define_name(string var, double val)
// add {var, val} to var_table
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var, val});
	return val;
}

// assume "let" has been seen
// handle: name = expressoin
// declare a variable called "name" with the initial value "expression"
double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	
	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (cin) 
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << '\n';
	} catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {
	calculate();
	return 0;
} catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c&& c != ';');
	return 1;
} catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

