//pancake sorter header
//window/graphics
#ifndef PANCAKESORTER_H
#define PANCAKESORTER_H

#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct PancakeSorter: Simple_window
{
	PancakeSorter(Point(xy),int w,int h,const string& title);	
	int level = 0;
	
	void startScreen(); //splash screen
	void detachSplash(); //detatch splash w/o redraw
	void startInstruct(); 
	void startGame();
	void showLevel();
	void setLevel(int numlvl);
	void hideButtons();
	void addPancake(int y, int w); //creates pancakes from 2-12
	void setPancakes(); //
	void drawPancakes(); //
	int getNumPancakes();

	Vector<Ellipse*> pancakes;

	static void cb_instruct(Address, Address window);
	static void cb_levelScreen(Address, Address window);
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

	//Splash Screen
	Rectangle bgcolor{Point{0,0},1000,800};
	Text gameTitle{Point{305,65},"The Flip-Flappening"};
	Text teamNumber{Point{445,120},"Team H11"};
	Text bl{Point{100,200},"Bofeng Li"};
	Text jc{Point{440,200},"Jasmin Cho"};
	Text jg{Point{730,200},"Jacob Goldsworthy"};
	Image mainPancakePic{Point{180,200},"mainpic.jpg"};
	Image sidePancakePic1{Point{5,600},"sidepan.jpg"};
	Image sidePancakePic2{Point{800,600},"sidepanflip.jpg"};
	Rectangle instruct{Point{350,715},98,30};
	Text instructLabel{Point{352,732},"  How to Play"};
	Button instructButton{Point{350,715},98,30,"  How to Play",cb_instruct};
	Rectangle levelScreen{Point{530,715},80,30};
	Text levelScreenLabel{Point{532,732},"   START"};
	Button levelScreenButton{Point{530,715},80,30,"   START",cb_levelScreen};
	


	//Level Screen
	Text levelText{Point{500,350},"Choose Level"};
	Button start{Point{450,700},70,30,"START",cb_start};
	Button two{Point{350,400},90,30,"Level 2",cb_two};
	Button three{Point{460,400},90,30,"Level 3",cb_three};
	Button four{Point{570,400},90,30,"Level 4",cb_four};
	Button five{Point{680,400},90,30,"Level 5",cb_five};
	Button six{Point{350,450},90,30,"Level 6",cb_six};
	Button seven{Point{460,450},90,30,"Level 7",cb_seven};
	Button eight{Point{570,450},90,30,"Level 8",cb_eight};
	Button nine{Point{680,450},90,30,"Level 9",cb_nine};
	Button ten{Point{350,500},90,30,"Level 10",cb_ten};
	Button eleven{Point{460,500},90,30,"Level 11",cb_eleven};
	Button twelve{Point{570,500},90,30,"Level 12",cb_twelve};

};
#endif