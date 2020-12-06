/*
	Oliver Andreae
	December 2015

	Solutions to PPP exercise 12 and 13

	Bulls and Cows (guessing game)
	- Four integers are generated in the range 0-9
	- The user must discover those numbers by repeated guesses

	Example
	- The number to be guessed is 1234
	- The user guesses 1359
	- Output "1 bull and 1 cow" 
		The user guessed one digit (1) correctly, in the correct position (a bull)
		The user guessed one digit (3) correctly, but in the wrong position (a cow)
	- Guessing contines until the user gets four bulls
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

inline void keep_window_open()
{
	cin.clear();
	cout << "\nPlease enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline int rand_int(int min, int max)
{
	random_device rd;
	static default_random_engine ran(rd());
	return uniform_int_distribution<>{min, max}(ran);
}

inline bool contains(const vector<int> v, int val)
{
	return find(v.begin(), v.end(), val) != v.end();
}

int main()
try {
	/*
		Pseudocode

		1. Prompt the user with instructions
		2. Generate random four digits and store in vector
		3. Input four-digit guess from user
		4. Compare each digit with digits in vector
			a. If digit is in vector, add one cow
			b. If digit is in vector and correct place, add one bull
		5. Output bulls and cows to user
		6. Repeat from 3 until user guesses four bulls
	*/

	//Output introductory story
	cout << "Bulls and Cows\n"
		"The farmer has secured the field with a four digit padlock code.\n"
		"As the farmer is on holiday, you must guess the digits so that you can feed his cattle.\n"
		"For each correct digit, in the correct place, you will be told you have one bull.\n"
		"For each correct digit, in the wrong place, you will be told you have one cow.\n"
		"Keep guessing until you have four bulls and you have solved the code!\n"
		"Remember, time is of the essence: the cattle are hungry!\n\n";

	//digits to guess
	vector<int> digits;
	while (digits.size() < 4) {
		int d = rand_int(0, 9);

		//ensure unique values
		if (!contains(digits, d))
			digits.push_back(d);
	}

	//true with four bulls
	bool locked = true;

	while (locked) {
		cout << "Please enter your four digits (separated by spaces): ";

		vector<int> guessed;
		guessed.reserve(4);

		//get user guesses and validate
		for (size_t i = 0; i < 4; i++) {
			int input = -1;
			cin >> input;

			//validate input range [0:9)
			if (input < 0 || input > 9)
				throw runtime_error("input must be within [0:9)");

			guessed.emplace_back(input);
		}

		int bulls = 0;
		int cows = 0;

		//compare guessed to actual digits
		for (size_t i = 0; i < guessed.size(); i++) {
			//compare each guessed to all digits
			for (size_t j = 0; j < digits.size(); j++) {
				//a guessed is the same as a digit
				if (guessed[i] == digits[j])
					//are they in the same positon?
					if (i == j)
						++bulls;
					else
						++cows;
			}
		}

		if (bulls == 4)
			locked = false;
		else
			cout << "You have " << bulls << " bulls and " << cows << " cows\n";
	}

	cout << "Congratulations! You have successfully cracked the farmer's code in time to feed the cattle\n";

	keep_window_open();

	return 0;
	
} catch (const std::exception& e) {
	cout << e.what();
	keep_window_open();
	return 1;
}