#include "Arc.h"


namespace Graph_lib {
	Arc::Arc(Graph_lib::Point p, int w, int h, int start, int end)
		: m_w{w}, m_h{h},m_start{start}, m_end{end}
	{
		if (end < start)
			throw Invalid_arc{"Arc end < start"};

		add(Graph_lib::Point{p.x-w, p.y-h});
	}

	void Arc::draw_lines() const
	{
		if (fill_color().visibility()) {
			fl_color(fill_color().as_int()); // fill
			fl_pie(point(0).x, point(0).y, m_w-1, m_h-1, m_start, m_end);
			fl_color(color().as_int()); // reset colour
		}

		// lines
		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, m_w, m_h, m_start, m_end); 
		}
	}
}
