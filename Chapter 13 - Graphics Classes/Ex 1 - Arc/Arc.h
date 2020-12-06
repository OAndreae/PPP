#pragma once
#include "../../Graph.h"
namespace Graph_lib {
	struct Arc : Graph_lib::Shape{
	public:
		class Invalid_arc : public std::invalid_argument { using invalid_argument::invalid_argument; };
		/// <summary>
		/// draws arc of ellipse
		/// </summary>
		/// <param name="p">centre point</param>
		/// <param name="w">width</param>
		/// <param name="h">height</param>
		/// <param name="start">start of arc in degrees [0:360]. 0 is 3 o'clock</param>
		/// <param name="end">end of arc in degrees [0:360]. 0 is 3 o'clock. must be less than start</param>
		Arc(Graph_lib::Point p, int w, int h, int start, int end);
		void draw_lines() const;
	private:
		int m_w;
		int m_h;
		int m_start;
		int m_end;
	};
}

