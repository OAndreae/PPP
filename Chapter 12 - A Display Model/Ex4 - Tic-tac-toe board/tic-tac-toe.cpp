// Oliver Andreae 27/05/2018
// A tic-tac-toe board of alternating white and red squares

#include "../../Graph.h"
#include "../../Simple_window.h"


#include <stdexcept>
#include <iostream>

inline bool is_odd(int n)
{
	return !(n%2==0);
}

void draw_grid(Simple_window& win, Graph_lib::Vector_ref<Graph_lib::Rectangle>& vr, int w, int h, Graph_lib::Color c1, Graph_lib::Color c2)
{
	constexpr int rect_h = 80;
	constexpr int rect_w = 80;

	for (size_t i = 0; i < h; ++i) { // row
		for (size_t j = 0; j < w; ++j) { // column

			// calculate points
			int x = j*rect_w;
			int y = i*rect_h;

			// draw rectangle
			using Graph_lib::Rectangle;
			vr.push_back(new Rectangle{Point{x,y}, rect_w, rect_h});
			
			// if row is odd
			//		if col is odd: c1
			//		else: c2
			// if row is even
			//		if col is odd: c2
			//		else: c1
			
			Color c = Color::black;
			if (is_odd(i)) 
				c=is_odd(j)?c1:c2;
			else
				c = is_odd(j)?c2:c1;

			// set last element added
			vr[vr.size()-1].set_fill_color(c);
			vr[vr.size()-1].set_color(Color::black);
			win.attach(vr[vr.size()-1]);
		}
	}
}

void draw_square(Simple_window* w, Graph_lib::Point xy, int size, Graph_lib::Color c)
{
	using Graph_lib::Rectangle;
	auto r = new Rectangle{xy, size,size};
	r->set_style(Graph_lib::Line_style::solid);
	r->set_fill_color(c);
	r->set_color(c);
	w->attach(*r);
}

int main()
try {
	using namespace Graph_lib;

	Point p{400,200};

	Simple_window win{p, 600, 400, "Tic-tac-toe board"};
	
	const Color c1 = Color::red;
	const Color c2 = Color::white;

	// storage
	Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;
	
	draw_grid(win, vr, 3, 3, c1, c2);

	win.wait_for_button();
} catch (const std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
} catch (...) {
	std::cerr << "error: " << "unhandled exception" << '\n';
	return 2;
}