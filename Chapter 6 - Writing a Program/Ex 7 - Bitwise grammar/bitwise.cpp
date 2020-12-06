/*
	Oliver Andreae
	December 2017
	Solution to exercise 6.12

	Bitwise logical expressions
	- Calculate the result bitwise expressions
	- Supported operators:
		- ! (not !1 = 0)
		- ~ (complement)
		- & (and)
		- | (or)
		- ^ (exclusive or)

	Grammar
	Expression:
		Term
		Term '^' Term
	Term:
		Primary
		Primary '&' Primary
	Primary:
		Byte
		'!' Byte
		'~' Byte
	Byte:
		binary-bit

*/