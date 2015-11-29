//pancake sorter header
//window/graphics

#ifndef PANCAKESORTER_H
#define PANCAKESORTER_H

#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"
#include "hiscore.h"

using namespace Graph_lib;

struct PancakeSorter: Simple_window
{
	// constants for pancakes and flip buttons
	const int CENTER_X = 500;
	const int PANCAKE_HEIGHT = 20;
	
	const int Y_DISTANCE = 40;
	const int Y_START = 700;
	
	const int WIDTH_START = 50;
	const int WIDTH_SCALE = 30;
	const int WIDTH_MAX = WIDTH_START+(WIDTH_SCALE*12)*2;

	const int FLIP_BUTTON_X = CENTER_X - (WIDTH_MAX / 2);
	const int FLIP_BUTTON_Y = Y_START - (PANCAKE_HEIGHT);

	// window
	PancakeSorter(Point(xy),int w,int h,const string& title);
	
	Vector<Ellipse*> pancakes; //ellipses vector
	Vector<int> pancakePos; //pancake positions vector
	Vector<HiScore> scores; //vector of 5 highest scores
	int level = 0;
	string player = "";	

	
	// Splash Screen
	void startScreen(); //opens level screen
	void startInstruct(); //opens instruction screen
	void detachSplash(); //detatch splash w/o redraw

	// Instruction Screen
	void back(); //back to splash screen from instruction screen

	// Level Chooser Screen
	void attachLevelButtons(); //attaches the buttons for level screen
	void startGame(); //starts actual game
	void showLevel(); //displays level on level screen
	void setLevel(int numlvl); //sets the chosen level
	void hideLevel(); //detaches all buttons on level screen
	void outputInitials(); //display player initials

	// Pancake functions
	int getNumPancakes(); //gets number of pancakes for certain level chosen
	void addPancake(int y, int w); //creates pancakes 2-12 and adds to vector of ellipses
	void attachPancakes(); //attaches pancake ellipses
	void detachPancakes(); //detaches pancake ellipses
	void shufflePancakes(); //randomly shuffles pancakes
	void addPancakeEllipses(); //draws the number of pancakes for chosen level
	void flipPancake(int pos); //flips the pancakes from chosen position
	void attachFlipButtons(); //attaches the buttons to flip pancakes
	void detachFlipButtons(); //detaches buttons to flip pancakes
	void moveFlipButton(Button &btn, int i); //moves the buttons to positions
	void movePancakes(int ellipseA, int ellipseB); //moves ellipses in flipPancake(int pos)
	void initializePancakePosition(); //adds positions from 1-total num pancakes
	void clearPancakes(); //clears pancakes in ellipse vector

	// Game Screen
	void exitGame(); //to exit game screen
	void makeFlipInvisible(); //make buttons invisible
	void calcScore(int numFlips, int timeLeft); //calculates player's final score
	void loadScores();

	// Callbacks for Start Screen
	static void cb_instruct(Address, Address window);
	static void cb_levelScreen(Address, Address window);

	// Callbacks for Instruction Screen
	static void cb_back(Address, Address window);

	// callbacks for level screen
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

	// Callbacks for Game Screen
	static void cb_exitGame(Address, Address window);
	static void cb_flip1(Address, Address window);
	static void cb_flip2(Address, Address window);
	static void cb_flip3(Address, Address window);
	static void cb_flip4(Address, Address window);
	static void cb_flip5(Address, Address window);
	static void cb_flip6(Address, Address window);
	static void cb_flip7(Address, Address window);
	static void cb_flip8(Address, Address window);
	static void cb_flip9(Address, Address window);
	static void cb_flip10(Address, Address window);
	static void cb_flip11(Address, Address window);

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
	In_box playerInitials{Point{500,250},100,50,"Input Player Initials: "};
	Text playerText{Point{500,250},player};
	Text levelText{Point{500,350},"Choose Level"};
	Button start{Point{450,700},90,30,"START",cb_start};
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

	Button p2{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 11", cb_flip11};
	Button p3{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(1 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 10", cb_flip10};
	Button p4{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(2 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 9", cb_flip9};
	Button p5{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(3 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 8", cb_flip8};
	Button p6{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(4 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 7", cb_flip7};
	Button p7{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(5 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 6", cb_flip6};
	Button p8{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(6 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 5", cb_flip5};
	Button p9{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(7 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 4", cb_flip4};
	Button p10{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(8 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 3", cb_flip3};
	Button p11{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(9 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 2", cb_flip2};
	Button p12{Point{ FLIP_BUTTON_X, FLIP_BUTTON_Y+(10 * Y_DISTANCE * -1)}, WIDTH_MAX, PANCAKE_HEIGHT * 2, "position 1", cb_flip1};

	Button exitButton{Point{100,100},90,30,"Quit",cb_exitGame};
	Button backButton{Point{100,100},90,30,"Back",cb_back};
};
#endif