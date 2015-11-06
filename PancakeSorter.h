//pancake sorter header
//window/graphics
#include "Simple_window.h"
#include "Graph.h"

struct PancakeSorter: Simple_window
{
	PancakeSorter(Point(xy),int w,int h,const string& title);	

	private:
		Button start{Point{450,640},70,30,"START",cb_start};

		Button two{Point{350,400},90,30,"2 Pancakes",cb_two};
		Button three{Point{460,400},90,30,"3 Pancakes",cb_three};
		Button four{Point{570,400},90,30,"4 Pancakes",cb_four};
		Button five{Point{680,400},90,30,"5 Pancakes",cb_five};

		Button six{Point{350,450},90,30,"6 Pancakes",cb_six};
		Button seven{Point{460,450},90,30,"7 Pancakes",cb_seven};
		Button eight{Point{570,450},90,30,"8 Pancakes",cb_eight};
		Button nine{Point{680,450},90,30,"9 Pancakes",cb_nine};

		Button ten{Point{350,500},90,30,"10 Pancakes",cb_ten};
		Button eleven{Point{460,500},90,30,"11 Pancakes",cb_eleven};
		Button twelve{Point{570,500},90,30,"12 Pancakes",cb_twelve};
		
		static void cb_start(Address, Address window);
		void startGame();
		static void cb_two(Address, Address window);
		static void cb_three(Address, Address window);
		static void cb_four(Address, Address window);
		static void cb_five(Address, Address window);
		static void cb_six(Address, Address window);
		static void cb_seven(Address, Address window);
		static void cb_eight(Address, Address window);
		static void cb_nine(Address, Address window);
		static void cb_ten(Address, Address window);
		static void cb_eleven(Address, Address window);
		static void cb_twelve(Address, Address window);
		void level(int lvl);
};