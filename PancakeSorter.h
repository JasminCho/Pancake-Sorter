//pancake sorter header
//window/graphics
#ifndef PANCAKESORTER_H
#define PANCAKESORTER_H

#include "Simple_window.h"
#include "Graph.h"

struct PancakeSorter: Simple_window
{
	PancakeSorter(Point(xy),int w,int h,const string& title);	
	int lvl = 0;
	void startGame();
	void setLevel(int numlvl);
	void hideButtons();
	void drawPancakes();
	void pancakeColor();

	Ellipse p1{Point{500,400},50,20};
	//Vector<Ellipse*> &pancake;

	static void cb_start(Address, Address window);
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

private:
	Text gameTitle{Point{500,100},"The Flip-Flappening"};
	Text levelText{Point{500,350},"Choose Level"};
	Button start{Point{450,640},70,30,"START",cb_start};

	Button two{Point{350,400},90,30,"Level 1",cb_two};
	Button three{Point{460,400},90,30,"Level 2",cb_three};
	Button four{Point{570,400},90,30,"Level 3",cb_four};
	Button five{Point{680,400},90,30,"Level 4",cb_five};

	Button six{Point{350,450},90,30,"Level 5",cb_six};
	Button seven{Point{460,450},90,30,"Level 6",cb_seven};
	Button eight{Point{570,450},90,30,"Level 7",cb_eight};
	Button nine{Point{680,450},90,30,"Level 8",cb_nine};

	Button ten{Point{350,500},90,30,"Level 9",cb_ten};
	Button eleven{Point{460,500},90,30,"Level 10",cb_eleven};
	Button twelve{Point{570,500},90,30,"Level 11",cb_twelve};
};
#endif