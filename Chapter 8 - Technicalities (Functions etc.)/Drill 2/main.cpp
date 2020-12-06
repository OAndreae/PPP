#include "..\..\std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_cr(const int& a, const int& b)
{
	int temp; 
	temp = a;
	//a = b;
	//b = temp;
}

int main()
{
	int x = 7;
	int y = 9;

	swap_v(x, y);
	cout << "x: " << x << "\ny: " << y << '\n';
	swap_r(x, y);
	cout << "\nx: " << x << "\ny: " << y << '\n';
	swap_cr(x, y);
	cout << "\nx: " << x << "\ny: " << y << '\n';

	swap_v(7, 9);
	//swap_r(7, 9);
	swap_cr(7, 9);

	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	cout << "cx: " << cx << "\ncy: " << cy << '\n';
	//swap_r(cx, cy);
	//cout << "\ncx: " << cx << "\ncy: " << cy << '\n';
	swap_cr(cx, cy);
	cout << "\ncx: " << cx << "\ncy: " << cy << '\n';

	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	cout << "dx: " << dx << "\ndy: " << dy << '\n';
	//swap_r(dx, dy);
	//cout << "\ndx: " << dx << "\ndy: " << dy << '\n';
	swap_cr(dx, dy);
	cout << "\ndx: " << dx << "\ndy: " << dy << '\n';

	swap_v(7.7, 9.9);
	//swap_r(7.7, 9.9);
	swap_cr(7.7, 9.9);

	char cc;
	cin >> cc;

}