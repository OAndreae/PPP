/*
	Oliver Andreae
	December 2017
	Solution to exercise 6.9

	Number Writer
	- Input upto a four digit number
	- Output it as thousands, hundreds, tens, and units
	- The number should be output as an int

	Example I/O
	> 1234
	1234 is 1 thousand, 2 hundreds, 3 tens and 4 ones
	
	> 201
	201 is 2 hundreds and 1 one
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

/// <summary>
/// prevents the console from closing immediately
/// </summary>
/// <param name="s">exit character</param>
inline void keep_window_open(string s)
{
	if (s == "") return;
	cin.clear();
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss != s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}
/*
	print digits + " is"
	let digit_pos = 0
	if (value at digit_pos != 0)
		let descriptor = descriptors.at(digits' length - digit position - 1)
	if (digit == 1)
		remove last character from descriptor
	if (digit_pos == last digit position && digits.size() > 1)
		print " and" digit " " descriptor
	else
		print " " digit " " descriptor
	repeat from for all digits
*/

void print_digits(const vector<int>& digits)
{
	if (digits.size() == 0) { // pointless continuing 
		cout << "no valid digits\n";
		return;
	}

	// digit descriptions
	const vector<string> descriptors = { "ones", "tens", "hundreds", "thousands", "ten thousands", "hundred thousands", "millions" };

	if (digits.size() > descriptors.size())
		throw invalid_argument("too many digits");

	// print original number
	for (auto& digit : digits) 
		cout << digit;

	cout << " is ";


	// print original number
	// if digit != 0, then print digit and word
	// if not last digit, print ' and '
	const size_t last_pos = digits.size() - 1;
	for (size_t i = 0; i < digits.size(); i++) {
		
		// skip e.g. "0 hundreds"
		if (digits[i] != 0) {
			string descriptor = descriptors.at(last_pos - i); // start from amount of digits and go back

			// make singular
			if (digits[i] == 1)
				descriptor.pop_back(); // remove 's'
		
			if (i != 0 && digits.at(i - 1) != 0)
				cout << " and ";

			cout << digits[i] << " " << descriptor;
		}
	}

	cout << '\n';
}


vector<int> get_digits()
{
	vector<int> digits;
	char c;
	while (cin.get(c) && !iswspace(c)) {
		int num = c - '0';

		if (num == 0 && digits.size() == 0)
			continue; // skip prefixing 0s
		
		if (isdigit(c))
			digits.push_back(num);
	}
	return digits;
}

int main()
try {
	/*
		Pseudo code (without error checking)

		1. Prompt user
		2. Input number
			a. input digit as char
			b. convert char to int and store in vector called digits
			c. repeat until input is terminated by a newline or there are four digits
		3. Output digits

			print digits + " is"
			let digit_pos = 0
			if (value at digit_pos != 0)
				let descriptor = descriptors.at(digits' length - digit position)
				if (digit == 1)
					remove last character from descriptor
				if (digit_pos == last digit position && digits.size() > 1)
					print " and" digit " " descriptor
				else
					print " " digit " " descriptor
			repeat from a. for all digits
	*/

	constexpr int max_digits = 7;
	constexpr char quit = '~';

	cout << "Please enter any up to " << max_digits << " digits. Enter " << quit << " to quit\n"
		<< "> ";
	
	vector<int> digits;

	// input up to four digits
	for (char c; cin >> c; cout << "> ") 
		try {
		if (c == quit) {
			cin.clear();
			break;
		} else
			cin.putback(c); // don't take first digit
		
		// input number and output words
			digits = get_digits();
			print_digits(digits);
		} catch (const exception& e) {
			cerr << "Error: " << e.what() << '\n';
		} catch (...) {
			cerr << "Something went wrong...\n";
			return 1;
		}
	
	keep_window_open("Fat");

	return 0;
} 
catch (const exception& e){
	cerr << e.what();
	keep_window_open("~");
	return 1;
}