//pancake sorter
#include <FL/fl_ask.H>
#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Simple_window{xy,w,h,title}
	{
		startScreen();
	}
void PancakeSorter::picAttach()
{
        //background
        bgcolor.set_fill_color(fl_rgb_color(16,179,122));
        attach(bgcolor);

        //images
        attach(mainPancakePic);
        attach(sidePancakePic1);
        attach(sidePancakePic2);

}

void PancakeSorter::startScreen()
{
	loadScores();
	picAttach();
	//Texts
	gameTitle.set_font(Graph_lib::Font::screen_bold);
	gameTitle.set_font_size(50);
	teamNumber.set_font_size(35);
	bl.set_font_size(30);
	jc.set_font_size(30);
	jg.set_font_size(30);
	attach(gameTitle);
	attach(teamNumber);
	attach(bl);
	attach(jc);
	attach(jg);

	//buttons
	instruct.set_fill_color(Color::white);
	instruct.set_color(Color::invisible);
	attach(instruct);
	instructLabel.set_font(Graph_lib::Font::screen_bold);
	attach(instructLabel);
	attach(instructButton);
	levelScreen.set_fill_color(Color::white);
	levelScreen.set_color(Color::invisible);
	attach(levelScreen);
	levelScreenLabel.set_font(Graph_lib::Font::screen_bold);
	attach(levelScreenLabel);
	attach(levelScreenButton);

}

void PancakeSorter::showLevel()
{
	detachSplash();
	
	attachLevelButtons();
	
	attach(playerInitials);
	attach(top5);
	attach(top5_1);
	attach(top5_2);
	attach(top5_3);
	attach(top5_4);
	attach(top5_5);

	displayScores();

	levelText.set_label("Choose Level");

	redraw();
}

void PancakeSorter::attachLevelButtons()
{
	attach(start);
	attach(two);
	attach(three);
	attach(four);
	attach(five);
	attach(six);
	attach(seven);
	attach(eight);
	attach(nine);
	attach(ten);
	attach(eleven);
	attach(twelve);
	attach(levelText);
}

void PancakeSorter::detachLevel()
{
	detach(start);
	detach(two);
	detach(three);
	detach(four);
	detach(five);
	detach(six);
	detach(seven);
	detach(eight);
	detach(nine);
	detach(ten);
	detach(eleven);
	detach(twelve);

	detach(levelText);

	detach(playerInitials);

	// top 5 scores
	detach(top5);
	detach(top5_1);
	detach(top5_2);
	detach(top5_3);
	detach(top5_4);
	detach(top5_5);
}

void PancakeSorter::attachFlipButtons()
{
	if(getNumPancakes() >= 2) { attach(p2); }
	if(getNumPancakes() >= 3) { attach(p3); }
	if(getNumPancakes() >= 4) { attach(p4); }
	if(getNumPancakes() >= 5) { attach(p5); }
	if(getNumPancakes() >= 6) { attach(p6); }
	if(getNumPancakes() >= 7) { attach(p7); }
	if(getNumPancakes() >= 8) { attach(p8); }
	if(getNumPancakes() >= 9) { attach(p9); }
	if(getNumPancakes() >= 10) { attach(p10); }
	if(getNumPancakes() >= 11) { attach(p11); }
	if(getNumPancakes() >= 12) { attach(p12); }
}

void PancakeSorter::detachFlipButtons()
{
	if(getNumPancakes() >= 2) { detach(p2); }
	if(getNumPancakes() >= 3) { detach(p3); }
	if(getNumPancakes() >= 4) { detach(p4); }
	if(getNumPancakes() >= 5) { detach(p5); }
	if(getNumPancakes() >= 6) { detach(p6); }
	if(getNumPancakes() >= 7) { detach(p7); }
	if(getNumPancakes() >= 8) { detach(p8); }
	if(getNumPancakes() >= 9) { detach(p9); }
	if(getNumPancakes() >= 10) { detach(p10); }
	if(getNumPancakes() >= 11) { detach(p11); }
	if(getNumPancakes() >= 12) { detach(p12); }
}

void PancakeSorter::detachSplash()
{
	detach(bgcolor);
	detach(mainPancakePic);
	detach(sidePancakePic1);
	detach(sidePancakePic2);
	detach(gameTitle);
	detach(teamNumber);
	detach(bl);
	detach(jc);
	detach(jg);
	detach(instruct);
	detach(instructLabel);
	detach(instructButton);
	detach(levelScreen);
	detach(levelScreenLabel);
	detach(levelScreenButton);
}

void PancakeSorter::startInstruct()
{
	detachSplash();
	bgcolor.set_fill_color(fl_rgb_color(30,216,230)); //background color
	attach(bgcolor);
	instTitle.set_font(Graph_lib::Font::screen_bold);
	instTitle.set_font_size(30);
	lineOne.set_font_size(20);
	lineTwo.set_font_size(20);
	lineThree.set_font_size(20);
	lineFour.set_font_size(20);
	lineFive.set_font_size(20);
	lineSix.set_font_size(20);
	attach(instTitle);
	attach(lineOne);
	attach(lineTwo);
	attach(lineThree);
	attach(lineFour);
	attach(lineFive);
	attach(lineSix);
	
	//button
	instToLevelRect.set_fill_color(Color::white);
	instToLevelRect.set_color(Color::invisible);
	attach(instToLevelRect);
	instToLevelLabel.set_font(Graph_lib::Font::screen_bold);
	attach(instToLevelLabel);
	attach(instructToLevel);
	
	redraw();
}

void PancakeSorter::detachInstruct()
{
	detach(instTitle);
	detach(lineOne);
	detach(lineTwo);
	detach(lineThree);
	detach(lineFour);
	detach(lineFive);
	detach(lineSix);
	detach(instToLevelRect);
	detach(instToLevelLabel);
	detach(instructToLevel);
	
}

void PancakeSorter::startFromInstruct()
{
	detachInstruct();
	showLevel();
	detach(instructToLevel);
	redraw();
}

void PancakeSorter::back()
{
	attachLevelButtons();
	attach(playerText);
	redraw();
}

void PancakeSorter::setLevel(int lvl)
{
	level = lvl;
	cout << "Number of Pancakes this level: " << getNumPancakes() << endl;
	string levelString = "Level " + to_string(lvl);
	levelText.set_label(levelString);

	redraw();
}

void PancakeSorter::attachEndScreen()
{
	detachFlipButtons();
	// show current player score
	attach(scoreText);
}

void PancakeSorter::detachEndScreen()
{
	detach(playerText);

	// hide current player score
	detach(scoreText);
	// hide current moves
	detach(movesText);
}

void PancakeSorter::gameWin()
{
	// you win!
	const char* winMessage = "You Win!! What do you want to do?";

	// For some stacks of more than 9 pancakes (like 1 2 3 4 5 6 10 9 8 7, with the 1 on top)
	//  this overestimates the minimum, so if the player actually gets the 
	// pancakes into order with fewer flips, add a “super bonus” of an extra 
	// 1000 points to the score with some message like “Wow!  You beat the computer!  
	//You win 1000 extra bonus points!”  Use this test case to be sure your bonus works.
	if(getNumPancakes() > 9)
	{
		if(moves < minMoves)
		{
			setPlayerScore(playerScore + 1000);
			winMessage = "You beat the computer! You get 1000 extra bonus points! What do you want to do?";
		}
	}

	newHiScore();
	saveScores();

	redraw();

	askPlayAgain(winMessage);
}

void PancakeSorter::gameLose()
{
	// you lose!
	askPlayAgain("You lose :( What do you want to do?");
}

void PancakeSorter::askPlayAgain(const char* message)
{
	const int BUTTON_PLAY_AGAIN = 0;
	const int BUTTON_LEVEL_SCREEN = 1;
	const int BUTTON_CLOSE_GAME = 2;

	int choice = fl_choice(message, "Play again", "Back", "Close game");

	if(choice == BUTTON_PLAY_AGAIN)
	{
		detachGameScreen();
		setupGame();
	}
	else if(choice == BUTTON_LEVEL_SCREEN)
	{
		exitGame();
	}
	else if(choice == BUTTON_CLOSE_GAME)
	{
		exit(0);
	}
}

bool PancakeSorter::checkInitials()
{
	if(getPlayerInitials() == "")
	{
		fl_alert("You must enter your initials");
		return false;
	}
	else
	{
		// check if initials are only letters
		string name = getPlayerInitials();
		const int ASCII_UPPER_A = 65;
		const int ASCII_UPPER_Z = 90;
		for(uint i = 0; i < name.size(); i++)
		{
			// only need to check A-Z, because getPlayerInitials() returns all caps
			if(name[i] < ASCII_UPPER_A || name[i] > ASCII_UPPER_Z)
			{
				fl_alert("Initials must be only be letters (A-Z)");
				return false;
			}
		}
	}

	return true;
}

bool PancakeSorter::checkErrors()
{
	if(level == 0)
	{
 		fl_alert("You must select a level");
 		return false;
	}
	else {
		return checkInitials();
	}
}

void PancakeSorter::startGame()
{
	if(!checkErrors())
	{
		return;
	}

	hintText.set_font_size(22);
	exitText.set_font_size(22);
	playerText.set_font_size(40);
	scoreText.set_font_size(50);
	movesText.set_font_size(40);
	minMovesText.set_font_size(40);


	// show current moves
	attach(movesText);
	attach(minMovesText);
	attach(playerText);
	playerText.set_label(getPlayerInitials());

	detachLevel();
	attach(exitButton);

	setupGame();

	redraw();
}

void PancakeSorter::setupGame()
{
	//attach background
	bgGameScreen.set_color(fl_rgb_color(255,255,255));
        bgGameScreen.set_fill_color(fl_rgb_color(255,255,255));
        attach(bgGameScreen);
	//redundancy is used to make sure the text is over the background
	detach(scoreText); detach(movesText);
	attach(scoreText); attach(movesText);
	detach(playerText); attach(playerText);
	detach(minMovesText); attach(minMovesText);
    // reset moves to 0
	setMoves(0);

	//add pancakes
	addPancakeEllipses();
	initializePancakePosition();
	// shuffle the pancakes
	shufflePancakes();
	// attach pancakes
	attachPancakes();
	attachFlipButtons();
	outputInitials();
	//attach hint, back, exit boxes, and background
	attach(hintButton);
	hintBox.set_fill_color(fl_rgb_color(255,215,0));
	exitBox.set_fill_color(fl_rgb_color(255,215,0));
	attach(hintBox); attach(hintText);
	attach(exitBox); attach(exitText);
	//calculate score
	calcMinMoves();
	calcScore();
	// calculate if the game has already been won by the random shuffle
	calcWinLose();
}

void PancakeSorter::detachGameScreen()
{
	clearPancakes();
	pancakes.clear();
	pancakePos.clear();
	detachFlipButtons();
	detach(hintButton);
	detach(bgGameScreen);
	detach(minMovesText);
	detach(hintBox); detach(hintText);
	detach(exitBox); detach(exitText);
}

void PancakeSorter::exitGame()
{
	
	detachGameScreen();
	detachEndScreen();
	detach(exitButton);
	showLevel();

	redraw();
}
