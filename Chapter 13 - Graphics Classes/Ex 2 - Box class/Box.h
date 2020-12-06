#pragma once
#include "../../Graph.h"
#include "../../Point.h"

namespace Graph_lib {
	class Box : public Graph_lib::Shape {
	public:
		class Invalid_roundness : public std::invalid_argument { using invalid_argument::invalid_argument; };
		Box(Graph_lib::Point p1, Graph_lib::Point p2, int r);
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="p">top left</param>
		/// <param name="w">width</param>
		/// <param name="h">height</param>
		/// 
		Box(Graph_lib::Point p, int w, int h, int r);

		void draw_lines() const;
	private:
		int m_w;
		int m_h;
		int m_r;
	};
}

