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
	void picAttach();  //attaches main pictures and background
	void startScreen(); //opens level screen
	void startInstruct(); //opens instruction screen
	void detachSplash(); //detatch splash w/o redraw

	// Instruction Screen
	void back(); //back to splash screen from instruction screen
	void detachInstruct();//detaches instruction
	void startFromInstruct();//from instruction to level screen

	// Level Chooser Screen
	void attachLevelOverlay(); //attach graphical indicators
	void attachLevelText(); 
	void attachLevelButtons(); //attaches the buttons for level screen
	void startGame(); //starts actual game
	void showLevel(); //displays level on level screen
	void setLevel(int numlvl); //sets the chosen level
	void detachLevelOverlay();
	void detachLevel(); //detaches all buttons on level screen and graphical objects
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
	bool checkErrors();
	bool checkInitials();
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
	static void hintFlashStart(void* hf);
	static void hintFlashEnd(void* hf);

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
	void setPlayerScore(int newScore);
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
	Text bl{Point{100,190},"Bofeng Li"};
	Text jc{Point{440,190},"Jasmin Cho"};
	Text jg{Point{730,190},"Jacob Goldsworthy"};
	Image mainPancakePic{Point{180,200},"mainpic.jpg"};
	Image sidePancakePic1{Point{5,550},"sidepan.jpg"};
	Image sidePancakePic2{Point{800,550},"sidepanflip.jpg"};
	
	Rectangle instruct{Point{360,715},98,30};
	Button instructButton{Point{360,715},98,30,"  How to Play",cb_instruct};
	Text instructLabel{Point{360,732},"  How to Play"};
	
	Rectangle levelScreen{Point{540,715},98,30};
	Button levelScreenButton{Point{540,715},98,30,"   START",cb_levelScreen};
	Text levelScreenLabel{Point{550,732},"   START"};

	//Instruction Screen
	
	Text instTitle{Point{400,65}, "Instructions"};
	Text lineOne{Point{25,160}, "The goal of this game is to arrange a stack of different size pancakes"};
	Text lineTwo{Point{25,205}, "from smallest on top to largest on bottom by repeatedly flipping"};
	Text lineThree{Point{25,250}, "over a top partial stack of some number of pancakes, you can insert between any two pancakes."};
	Text lineFour{Point{25,295}, "You can click on the 'hint' button and it will tell you the next best move."};
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

	// initials
		//four Rectangle background
	Rectangle bgLevel1{Point{0,0},1000,250};
	Rectangle bgLevel2{Point{0,0},480,850};
	Rectangle bgLevel3{Point{580,0},600,850};
	Rectangle bgLevel4{Point{480,300},100,500};
		//In box
	In_box playerInitials{Point{480,250},100,50,"Input Player Initials: "};
	Text initialsPrompt{Point{350,280},"Input Player Initials: "};
	Text levelText{Point{450,350},"Choose Level"};
		//start
	Button start{Point{460,700},90,30,"START",cb_start};
	Rectangle startR{Point{460,700},90,30};
	Text startT{Point{487,717},"Start"};
		//2
	Button two{Point{295,400},90,30,"Level 2",cb_two};
	Rectangle twoR{Point{295,400},90,30};
	Text twoT{Point{317,417},"Level 2"};
		//3
	Button three{Point{405,400},90,30,"Level 3",cb_three};
	Rectangle threeR{Point{405,400},90,30};
	Text threeT{Point{427,417},"Level 3"};
		//4
	Button four{Point{515,400},90,30,"Level 4",cb_four};
	Rectangle fourR{Point{515,400},90,30};
	Text fourT{Point{537,417},"Level 4"};
		//5
	Button five{Point{625,400},90,30,"Level 5",cb_five};
	Rectangle fiveR{Point{625,400},90,30};
	Text fiveT{Point{647,417},"Level 5"};
		//6
	Button six{Point{295,450},90,30,"Level 6",cb_six};
	Rectangle sixR{Point{295,450},90,30};
	Text sixT{Point{317,467},"Level 6"};
		//7
	Button seven{Point{405,450},90,30,"Level 7",cb_seven};
	Rectangle sevenR{Point{405,450},90,30};
	Text sevenT{Point{427,467},"level 7"};
		//8
	Button eight{Point{515,450},90,30,"Level 8",cb_eight};
	Rectangle eightR{Point{515,450},90,30};
	Text eightT{Point{537,467},"Level 8"};
		//9
	Button nine{Point{625,450},90,30,"Level 9",cb_nine};
	Rectangle nineR{Point{625,450},90,30};
	Text nineT{Point{647,467},"Level 9"};
		//10
	Button ten{Point{350,500},90,30,"Level 10",cb_ten};
	Rectangle tenR{Point{350,500},90,30};
	Text tenT{Point{370,517},"Level 10"};
		//11
	Button eleven{Point{460,500},90,30,"Level 11",cb_eleven};
	Rectangle elevenR{Point{460,500},90,30};
	Text elevenT{Point{480,517},"Level 11"};
		//12
	Button twelve{Point{570,500},90,30,"Level 12",cb_twelve};
	Rectangle twelveR{Point{570,500},90,30};
	Text twelveT{Point{590,517},"Level 12"};

	// Game Screen Objects
	Text scoreText{Point{390, 210}, ""};
	Text movesText{Point{430, 160}, ""};
	Text minMovesText{Point{330, 110}, ""};
	Text playerText{Point{465,60},""};

	Button hintButton{Point{20, 20}, 90, 30, "Hint", cb_hint};
	Rectangle hintBox{Point{20,20},90,30};
	Text hintText{Point{45,43},"Hint"};
	Button exitButton{Point{120,20},90,30,"Back",cb_exitGame};
	Rectangle exitBox{Point{120,20},90,30};
	Text exitText{Point{140,43},"Back"};
	

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
};
#endif
