//pancake sorter header

#include "Window.h"
#include "Graph.h"

struct PancakeSorter:Fl_Window
{
	PancakeSorter(Point(xy),int w,int h,const string& title);	

	private:
		Button start{Point{340,100},70,20,"ON/OFF",cb_on};
};