// Oliver Andreae 16/6/2018
// PPP2 exercise 13.1 - define class Arc to draw part of an ellipse
#include "Arc.h"

#include "../../std_lib_facilities.h"
#include "../../Simple_window.h"

#include <iostream>

int main()
try {
	Simple_window win{Point{100,100}, 800,600, "PPP2 ex. 13.1 - arc"};

	using namespace Graph_lib;
	using Graph_lib::Arc;

	Arc a1{Point{400,300}, 100, 150, 180,360};
	a1.set_fill_color(Graph_lib::Color::red);
	win.attach(a1);

	Arc a2{Point{400,300}, 100, 150, 0, 180};
	a2.set_color(Color::cyan);
	a2.set_fill_color(Color::white);
	win.attach(a2);


	Arc a3{Point{200,500}, 200, 150, 0, 65};
	a3.set_color(Color::blue);
	win.attach(a3);


	win.wait_for_button();
} catch (const std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	keep_window_open();
}