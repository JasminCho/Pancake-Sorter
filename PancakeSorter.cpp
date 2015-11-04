//pancake sorter

#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Fl_Window{xy,w,h,title}
	{
		attach(start);
	}