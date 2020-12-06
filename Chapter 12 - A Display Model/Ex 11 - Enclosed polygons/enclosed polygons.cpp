#define _USE_MATH_DEFINES
#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"

#include <iostream>
#include <cmath>
#include <memory>

using namespace Graph_lib;

double to_radian(double d)
{
	return d * M_PI/180; //?????? ERROR??
}

// returns vector of points for n-sided regular polygon
// with apothem, a around origin, o
// rotation (radians), r
vector<Point> ngon_points(Point o, int n, double a, int r=0)
{
	vector<Point> points;

	for (size_t i = 0; i < n; i++) {
		double theta = to_radian((i+1)*(360/n) + r); // calculate current interior angle

		double x = a*cos(theta);
		double y = a*sin(theta);
		
		Point xy;
		xy.x = o.x + x;
		xy.y = o.y + y;
		
		points.push_back(xy); // add xy in relation to o
	}

	return points;
}

//void draw_polygon(Graph_lib::Window& win, const vector<Point>& ps, Color c)
//{
//	
//	Graph_lib::Polygon* p = new Polygon;
//	for (auto& i : ps)
//		p.add(i);
//	p.set_color(c);
//
//	static vector<Graph_lib::Shape*> polys;
//
//	polys.push_back(p);
//
//	win.attach(p);
//}

/// <summary>
/// next apothem
/// </summary>
/// <param name="a">current apothem</param>
/// <returns>next apothem</returns>
//double apothem(double a)
//{
//
//}
//
int main()
try {
	Point win_xy{300,300};
	constexpr int win_w = 600;
	constexpr int win_h = 400;
	Simple_window win{win_xy, win_w, win_h, "Enclosed polygons"};

	Point o{(int)std::round(.5*win_w),(int)std::round(.5*win_h)}; // origin; middle of window

	// initial number of sides
	const int n_sides = 5;
	
	// distance from origin to first polygon's vertcies
	double apothem = 100;

	using Graph_lib::Polygon;
	Vector_ref<Polygon> vr;
	
	// draw polygons
	for (size_t i = n_sides; i >= 3; --i) {
		vr.push_back(new Polygon{});
		
		double theta = to_radian(360/i);
		apothem = apothem * cos(theta/2);

		int div_angle = 180*(i-2))

		// generate and add points
		auto points = ngon_points(o, i, apothem,i*54);		
		vr[vr.size()-1].set_color(Color::red);

		for (auto& i : points)
			vr[vr.size()-1].add(i);
		
		// attach last polygon in vr
		win.attach(vr[vr.size()-1]);

		win.wait_for_button();
	}

	win.wait_for_button();
} catch (const std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
} catch (...) {
	std::cerr << "error: unhandled exception\n";
	return 2;
}