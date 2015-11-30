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

	// pancake Color
	Color getPancakeColor();

	// window
	PancakeSorter(Point(xy),int w,int h,const string& title);

	Vector<Ellipse*> pancakes; //ellipses vector
	Vector<int> pancakePos; //pancake positions vector
	Vector<HiScore> scores; //vector of 5 highest scores
	int level = 0;
	int moves = 0;

	// Splash Screen
	void startScreen(); //opens level screen
	void startInstruct(); //opens instruction screen
	void detachSplash(); //detatch splash w/o redraw

	// Instruction Screen
	void back(); //back to splash screen from instruction screen
	void detachInstruct();//detaches instruction
	void startFromInstruct();//from instruction to level screen

	// Level Chooser Screen
	void attachLevelButtons(); //attaches the buttons for level screen
	void startGame(); //starts actual game
	void showLevel(); //displays level on level screen
	void setLevel(int numlvl); //sets the chosen level
	void detachLevel(); //detaches all buttons on level screen
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
	void setupGame();
	void exitGame(); //to exit game screen
	void calcScore(); //calculates player's final score
	void loadScores();
	void saveScores();
	void displayScores();
	void displayScores(Text &text, int index);
	void setMoves(int newMoves);
	void detachGameScreen();
	void gameLose();
	void gameWin();
	void hint();
	int minMoves = 0;
	void calcMinMoves();
	void calcWinLose();

	// Win Screen
	void attachEndScreen();
	void detachEndScreen();
	void askPlayAgain(const char* message); // const char* instead of string because fltk

	// Score
	vector<int>* getSolution();
	string getPlayerInitials();
	void newHiScore();
	void sortHiScores();
	int playerScore;


	// Callbacks for Start Screen
	static void cb_instruct(Address, Address window);
	static void cb_levelScreen(Address, Address window);

	// Callbacks for Instruction Screen
	static void cb_back(Address, Address window);
	static void cb_instructToLevel(Address, Address window);

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
	static void cb_hint(Address, Address window);
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
	Image sidePancakePic1{Point{5,550},"sidepan.jpg"};
	Image sidePancakePic2{Point{800,550},"sidepanflip.jpg"};
	Rectangle instruct{Point{350,715},98,30};
	Text instructLabel{Point{350,730},"  How to Play"};
	Button instructButton{Point{350,756},98,30,"  How to Play",cb_instruct};
	Rectangle levelScreen{Point{530,715},98,30};
	Text levelScreenLabel{Point{540,728},"   START"};
	Button levelScreenButton{Point{530,756},98,30,"   START",cb_levelScreen};

	//Instruction Screen
	
	Text instTitle{Point{400,65}, "Instructions"};
	Text lineOne{Point{25,160}, "The goal of this game is to arrange a stack of different size pancakes"};
	Text lineTwo{Point{25,205}, "from smallest on top to largest on bottom by repeatedly flipping"};
	Text lineThree{Point{25,250}, "over a top partial stack of some number of pancakes, you can insert between any two pancakes."};
	Text lineFour{Point{25,295}, "There will be a timer to show how much time is left for you to complete the game."};
	Text lineFive{Point{25,340}, "The game is over when pancakes are sorted and top scores will be recorded."};
	Text lineSix{Point{25,385}, "Your score is 0 if you do too many flips."};
	Rectangle instToLevelRect{Point{450,700},90,30};
	Text instToLevelLabel{Point{453,715},"    START"};
	Button instructToLevel{Point{450,700},90,30,"START",cb_instructToLevel};


	// Level Screen Objects
	// hiscores
	Text top5{Point{100,100},"Top 5 Hi-Scores"};
	Text top5_1{Point{100,120},""};
	Text top5_2{Point{100,140},""};
	Text top5_3{Point{100,160},""};
	Text top5_4{Point{100,180},""};
	Text top5_5{Point{100,200},""};
	Text scoreText{Point{500, 200}, ""};
	Text movesText{Point{500, 150}, ""};
	// initials
	In_box playerInitials{Point{500,250},100,50,"Input Player Initials: "};
	Text playerText{Point{500,250},""};
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

	// Game Screen Objects
	Rectangle bgGameScreen{Point{0,0},1000,800};
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

	Button hintButton{Point{200, 100}, 90, 30, "Hint", cb_hint};
	Rectangle hintBox{Point{200,100},90,30};
	Text hintText{Point{215,125},"Hint"};
	Button exitButton{Point{300,100},90,30,"Quit",cb_exitGame};
	Rectangle exitBox{Point{300,100},90,30};
	Text exitText{Point{315,125},"Exit"};
	Button backButton{Point{100,100},90,30,"Back",cb_back};
	Rectangle backBox{Point{100,100},90,30};
	Text backText{Point{115,125},"Back"};
};
#endif
