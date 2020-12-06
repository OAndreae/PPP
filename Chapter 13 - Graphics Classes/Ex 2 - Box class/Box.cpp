#include "Box.h"

namespace Graph_lib {

	Box::Box(Graph_lib::Point p, int w, int h, int r)
		: m_w{w}, m_h{h}, m_r{r}
	{
		int min_length = w < h?w:h;
		if (r > min_length) {
			throw Invalid_roundness{"r > min length"};
			return;
		}

		Shape::add(p); // top left
		Shape::add(Point{p.x + w,p.y}); // top right
		Shape::add(Point{p.x + w, p.y + h}); // bottom right
		Shape::add(Point{p.x, p.y + h}); // bottom left
	}


	Box::Box(Graph_lib::Point p1, Graph_lib::Point p2, int r)
	{
		Box(p1, p1.x + p2.x, p1.y + p2.y, r);
		//Point top_r{p2.x, p1.y};
		//Point bottom_l{p1.x, p2.y};

		//Shape::add(p1); // top left
		//Shape::add(top_r);
		//Shape::add(p2); // bottom right
		//Shape::add(bottom_l);
	}

	void Box::draw_lines() const
	{
		// fill
		if (fill_color().visibility()) { 
			fl_color(fill_color().as_int());
			// draw first 3 lines
			fl_begin_complex_polygon();
			for (int i = 0; i<number_of_points(); ++i) 
				fl_vertex(point(i).x, point(i).y);		
			// draw final line; connect last to first
			fl_line(point(3).x, point(3).y, point(0).x, point(0).y);
			fl_end_complex_polygon();

			fl_color(color().as_int());	// reset colour
		}

		// lines on top of fill
		if (color().visibility()) { 
			fl_color(color().as_int());

			const int r = 50; // radius; curve value
						
			fl_begin_line();
			fl_arc(point(0).x + m_r, point(0).y + m_r, m_r, 90, 180); // top left
			fl_arc(point(3).x + m_r, point(3).y - m_r, m_r, 180, 270); // bottom left
			fl_arc(point(2).x - m_r, point(2).y - m_r, m_r, 270, 360); // bottom left
			fl_arc(point(1).x - m_r, point(1).y + m_r, m_r, 0, 90); // top right
			fl_line(point(0).x + m_r, point(0).y, point(1).x - m_r, point(1).y); // connect TL and TR
			fl_end_line();
		}

	}
}

