// Oliver Andreae 17/6/2018
// PPP2 exercise 13.2 - define class Box to with rounded corners
#include "Box.h"
#include "../Ex 1 - Arc/Arc.h"

#include "../../std_lib_facilities.h"
#include "../../Simple_window.h"

#include <iostream>

int main()
try {
	Simple_window win{Point{100,100}, 800,600, "PPP2 ex. 13.2 - box"};

	using namespace Graph_lib;
	
	Box b{Point{200,200}, 400,100,100};
	b.set_color(Color::black);

	win.attach(b);
	win.wait_for_button();
} catch (const std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	keep_window_open();
}