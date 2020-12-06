// Oliver Andreae 10/06/2018
// PPP2 Chapter 13 Drill

#include "../../Simple_window.h"
#include "../../Graph.h"

#include <iostream>

int main()
try {

	using namespace Graph_lib;
	Simple_window win{Point{100,100}, 800,1000, "Chapter 13 Drill"};

	// make 8-by-8 grid on leftmost 800-by-800 part of win
	constexpr int x_grid = 100;
	constexpr int y_grid = 100;
	constexpr int rows = 8;
	constexpr int columns = 8;
	constexpr int x_size = x_grid * columns;
	constexpr int y_size = y_grid * rows;

	Lines grid;
	grid.set_color(Graph_lib::Color::black);

	// add vertical (x) lines
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{x,0}, Point{x,x_size});
	// add horizontal (y) lines
	for (int y = 0; y < y_size; y += y_grid)
		grid.add(Point{0, y}, Point{y_size, y});

	win.attach(grid);

	// add image behind red squares
	Vector_ref<Image> imgs;
	for (int i = 0; i < 3; i++) {
		Point p{i*2*x_grid, i*2*y_grid};
		imgs.push_back(new Image{p, "..\\..\\resources\\Charles Rolls.jpg", Suffix::jpg});
		win.attach(imgs[imgs.size()-1]);
	}

	Vector_ref<Graph_lib::Rectangle> rects;

	// draw red rectangles across diagonal
	for (int i = 0; i<columns; ++i) {
		Point px{i*x_grid, i*y_grid};
		Point py{(i+1)*x_grid, (i+1)*y_grid};

		Graph_lib::Rectangle{px,py};
		rects.push_back(new Graph_lib::Rectangle{px,py});
		rects[rects.size()-1].set_color(Color::red);
		rects[rects.size()-1].set_style(Line_style::Line_style(Line_style::solid, 5));

		win.attach(rects[rects.size()-1]);
	}

	Image small_img{Point{0,0}, "..\\..\\resources\\fathers day.jpg", Suffix::jpg};
	win.attach(small_img);
	
	// move image when 'Next' clicked
	// to random square
	// max five times
	for (int i = 0; i < 10; ++i) {
		win.wait_for_button();
		Point p{100*randint(columns-1), 100*randint(rows-1)};
		small_img.move(p.x - small_img.point(0).x, p.y - small_img.point(0).y);
	}

	win.wait_for_button();
} catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
} catch (...) {
	std::cerr << "error: " << "unhandled exception\n";
}