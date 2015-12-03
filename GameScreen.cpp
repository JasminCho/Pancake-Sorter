#include <FL/fl_ask.H>
#include "PancakeSorter.h"

//GameScreen
void PancakeSorter::startGame() 
{
	if(!checkErrors())
	{
		return;
	}

	detachLevelScreen();
	
	setGameGraphics();
	attachGameGraphics();
	setupGame();

	redraw();
}

void PancakeSorter::setupGame() 
{
    // reset moves to 0
	setMoves(0);
	// start the timer
	setupTimer();
	// add pancakes
	addPancakeEllipses();
	initializePancakePosition();
	// shuffle the pancakes
	shufflePancakes();
	outputInitials();
	attachPancakes();
	// calculate score
	calcMinMoves();
	calcScore();
	// calculate if the game has already been won by the random shuffle
	calcWinLose();
}

void PancakeSorter::attachGameGraphics()
{
	// attach background
    attach(bgGameScreen);
	// attach hint, back, exit boxes, and background
	attachFlipButtons();
	attach(hintButton);
	attach(exitButton);
	attach(exitRect);
	attach(exitText);
	attach(hintRect); 
	attach(hintText);
	attach(movesText);
	attach(minMovesText);
	attach(playerText);

	attach(timerText);
}

void PancakeSorter::setGameGraphics()
{
	hintText.set_font_size(22);
	exitText.set_font_size(22);
	playerText.set_font_size(40);
	scoreText.set_font_size(50);
	movesText.set_font_size(40);
	minMovesText.set_font_size(40);
	playerText.set_label(getPlayerInitials());
	bgGameScreen.set_color(fl_rgb_color(255,255,255));
    bgGameScreen.set_fill_color(fl_rgb_color(255,255,255));
    hintRect.set_fill_color(fl_rgb_color(255,215,0));
	exitRect.set_fill_color(fl_rgb_color(255,215,0));
}

void PancakeSorter::detachGameScreen() // detaches the game screen
{
	clearPancakes();
	pancakes.clear();
	pancakePos.clear();
	detachFlipButtons();
	detach(hintButton);
	detach(exitButton);
	detach(bgGameScreen);
	
	detach(hintRect);
	detach(exitRect); 
	detach(hintText);
	detach(exitText);
	detach(minMovesText);
	detach(movesText);
}

void PancakeSorter::exitGame()
{	
	stopTimer();
	detachEndScreen();
	detachGameScreen();
	attachLevelScreen();
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

void PancakeSorter::attachEndScreen()
{
	attach(scoreText);
	detachFlipButtons();
	// show current player score
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

	if(getNumPancakes() > 9) // Bonus points!
	{
		if(moves < minMoves)
		{
			setPlayerScore(playerScore + 1000);
			winMessage = "You beat the computer! You get 1000 extra bonus points! What do you want to do?";
		}
	}

	timerEnabled = false;
	newHiScore();
	saveScores();

	askPlayAgain(winMessage);
}

void PancakeSorter::gameLose()
{
	// you lose!
	// stop the game timer
	stopTimer();
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
		detachEndScreen();
		detachGameScreen();
		setGameGraphics();
		attachGameGraphics();
		setupGame();

		redraw();
	}
	else if(choice == BUTTON_LEVEL_SCREEN)
	{
		detachEndScreen();
		detachGameScreen();
		attachLevelScreen();
	}
	else if(choice == BUTTON_CLOSE_GAME)
	{
		exit(0);
	}
}

void PancakeSorter::outputInitials()
{
	string player = getPlayerInitials();
}

