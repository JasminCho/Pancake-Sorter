//pancake sorter header
//window/grpahics

#include "Simple_window.h"
#include "Graph.h"

struct PancakeSorter: Simple_window
{
	PancakeSorter(Point(xy),int w,int h,const string& title);	

	private:
		Button start{Point{450,600},70,20,"START",cb_start};
		
		static void cb_start(Address, Address window);
		void startGame();
};