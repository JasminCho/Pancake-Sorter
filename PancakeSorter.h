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
	void hide_flip_buttons();
	void show_flip_buttons();
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
//Pancake flip cb
	static void cb_flip2(Address,Address window);
        static void cb_flip3(Address,Address window);
        static void cb_flip4(Address,Address window);
        static void cb_flip5(Address,Address window);
        static void cb_flip6(Address,Address window);
        static void cb_flip7(Address,Address window);
        static void cb_flip8(Address,Address window);
        static void cb_flip9(Address,Address window);
        static void cb_flip10(Address,Address window);
        static void cb_flip11(Address,Address window);
        static void cb_flip12(Address,Address window);


private:

	//Splash Screen
	Rectangle bgcolor{Point{0,0},1000,800};
	Text gameTitle{Point{305,65},"The Flip-Flappening"};
	Text teamNumber{Point{445,120},"Team H11"};
	Text bl{Point{100,200},"Bofeng Li"};
	Text jc{Point{440,200},"Jasmin Cho"};
	Text jg{Point{730,200},"Jacob Goldsworthy"};
	Image mainPancakePic{Point{180,200},"mainpic.jpg"};
	Image sidePancakePic1{Point{5,515},"sidepan.jpg"};
	Image sidePancakePic2{Point{800,515},"sidepanflip.jpg"};
	Rectangle instruct{Point{350,660},98,30};
	Text instructLabel{Point{352,680},"  How to Play"};
	Button instructButton{Point{350,660},98,30,"  How to Play",cb_instruct};
	Rectangle levelScreen{Point{530,660},80,30};
	Text levelScreenLabel{Point{532,680},"   START"};
	Button levelScreenButton{Point{530,660},80,30,"   START",cb_levelScreen};



	//Level Screen
	Text levelText{Point{500,350},"Choose Level"};
	Button start{Point{450,650},70,30,"START",cb_start};
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
//////////////Pancake Flipping Buttons////////////
	Button flip2{Point{150,187},700,42," ",cb_flip2};
        Button flip3{Point{150,187+1*41},700,41," ",cb_flip3};
        Button flip4{Point{150,187+2*41},700,41," ",cb_flip4};
        Button flip5{Point{150,187+3*41},700,41," ",cb_flip5};
        Button flip6{Point{150,187+4*41-1},700,41," ",cb_flip6};
        Button flip7{Point{150,187+5*41-1},700,41," ",cb_flip7};
        Button flip8{Point{150,187+6*41-1},700,41," ",cb_flip8};
        Button flip9{Point{150,187+7*41-3},700,41," ",cb_flip9};
        Button flip10{Point{150,187+8*41-3},700,41," ",cb_flip10};
        Button flip11{Point{150,187+9*41-4},700,41," ",cb_flip11};
        Button flip12{Point{150,187+10*41-4},700,41," ",cb_flip12};
};
#endif
