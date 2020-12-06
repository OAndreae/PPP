// Oliver Andreae 31/12/2017
// Solution to PPP2 chapter 10 dril
/*
	- Input Points (x,y) from the user and
		store in vector called original_points
	- Print original_points
	- Output original_points to a file called mydata.txt
	- Read data from mydata.txt and store in vector
		called processed_points
	- Print data from both vectors
	- Compare data in both vectors and print
		"Something's wrong" if the number of elements 
		or the value of elements differ
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Point {
	int x;
	int y;
};

// output Point
std::ostream& operator<<(std::ostream& os, const Point& p)
{
	return os << '(' << p.x << ", " << p.y << ')';
}

// input Point as "(x, y)" where x and y are integer
std::istream& operator>>(std::istream& is, Point& p)
{
	// throw if bad
	is.exceptions(is.exceptions() | std::ios_base::badbit);

	char c1;
	if (is >> c1 && c1 != '(') { // could it be a Point?
		is.unget();
		is.clear(std::ios_base::failbit); // indicate 'fail'
		return is;
	}

	// read x
	int x;
	is >> x;
	p.x = x;

	// try to read separator
	char c2;
	if (is >> c2 && c2 != ',') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	// read y and closing Point marker ')'
	int y;
	char c3;
	if (is >> y >> c3 && c3 != ')') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}
	p.y = y;

	// successfully read Point!
	return is;
}

bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x
		&& a.y == b.y;
}

bool operator!=(const Point& a, const Point& b)
{
	return !(a == b);
}


/// <summary>
/// output <paramref name="msg"/> if the state of <paramref name="is"/> is fail()
/// and the last character read isn't <paramref name="term"/>
/// </summary>
/// <param name="is">input stream</param>
/// <param name="term">terminator/separator character</param>
/// <param name="msg">error message</param>
void end_of_loop(std::istream& is, char term, const std::string& msg)
{
	// use term as terminator and/or separator
	if (is.fail()) {
		is.clear(); // look at last character
		char ch;
		if (is >> ch && ch == term) return; // all is fine
		std::cerr << msg << '\n';
	}
}

void keep_window_open()
{
	std::cout << "Please enter any character to exit...";

	std::cin.clear();
	char ch;
	std::cin >> ch;
}

/// <summary>
/// output data to file called <paramref name="name"/>
/// </summary>
/// <param name="data">Point vector</param>
/// <param name="name">file name including extension</param>
void write_data(const std::vector<Point>& data, const std::string& name)
{
	std::ofstream data_out{name};
	
	// does name contain a dot?
	if (!data_out) throw std::runtime_error{"error opening file for writing: '" + name + "'"};

	for (auto& p : data)
		data_out << p << '\n';
}

void read_data(std::vector<Point>& ps, const std::string& file_name)
{
	std::ifstream is{file_name};
	if(!is) throw std::runtime_error{"error opening file for reading: '" + file_name + "'"};

	// read data from file until error or eof()
	while (true) {
		Point p;
		if (!(is >> p)) break;
		ps.push_back(p);
	}
	end_of_loop(is, '|', "error reading from " + file_name);
}

inline void print(const std::vector<Point>& ps)
{
	for (auto& p : ps)
		std::cout << p << "\n";
}

// compare each element and throw if error
// output a and b
void compare_print(const std::vector<Point>& a, const std::vector<Point>& b)
try {
	if (a.size() != b.size()) throw std::runtime_error{"a and b differ in size"};

	for (size_t i = 0; i < a.size(); i++) {
		// compare
		if (a[i] != b[i]) throw std::runtime_error{"elements differ at " + i};
		// print as table
		std::cout << a[i] << '\t' << b[i] << '\n';
	}
} catch (const std::runtime_error& e) {
	std::cerr << "Something's wrong!: compare_print(): " << e.what();
}

int main()
{
	using std::cout;

	constexpr char term = '|';

	cout << "Please enter points in the form (x, y), where x and y are intergers.\n"
		"Enter " << term << " to stop\n";

	std::vector<Point> original_points;

	// read Point(s)
	while (true) {
		cout << '>';

		// read Point
		Point p;
		if (!(std::cin >> p)) break; // error or terminator

		original_points.push_back(p);
	}
	end_of_loop(std::cin, term, "error reading Point");

	print(original_points);
	
	// output Points to mydata.txt
	write_data(original_points, "mydata.txt");

	std::vector<Point> processed_points;
	read_data(processed_points, "mydata.txt");

	cout << "\nComparison\n";
	compare_print(original_points, processed_points);

	keep_window_open();
}