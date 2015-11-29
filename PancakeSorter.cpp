//pancake sorter

#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Simple_window{xy,w,h,title}
	{
		startScreen();
	}

void PancakeSorter::startScreen()
{
	loadScores();
	//background
	bgcolor.set_fill_color(fl_rgb_color(16,179,122));
	attach(bgcolor);
	
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

	attach(mainPancakePic);
	attach(sidePancakePic1);
	attach(sidePancakePic2);
}

void PancakeSorter::showLevel()
{
	detachSplash();
	attach(playerInitials);
	attachLevelButtons();
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

void PancakeSorter::hideLevel()
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
	makeFlipInvisible();
}

void PancakeSorter::makeFlipInvisible()
{
	p2.hide_border();
	p3.hide_border();
	p4.hide_border();
	p5.hide_border();
	p6.hide_border();
	p7.hide_border();
	p8.hide_border();
	p9.hide_border();
	p10.hide_border();
	p11.hide_border();
	p12.hide_border();
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
	attach(backButton);
	redraw();
}

void PancakeSorter::back()
{
	attachLevelButtons();
	attach(playerText);
	detach(backButton);
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

void PancakeSorter::startGame()
{
	// if(level==0)
	// {
	// 	popup a window saying NO
	// }

	detach(levelText);

	attach(playerText);
	playerText.set_label(playerInitials.get_string());

	hideLevel();
	//add pancakes
	addPancakeEllipses();
	// shuffle the pancakes
	shufflePancakes();
	initializePancakePosition();
	// attach pancakes
	attachPancakes();
	attach(exitButton);
	hideLevel();
	attachFlipButtons();
	outputInitials();
	detach(playerInitials);
	redraw();
}

void PancakeSorter::exitGame()
{
	clearPancakes();
	detach(exitButton);
	detach(playerText);
	pancakes.clear();
	pancakePos.clear();
	attachLevelButtons();
	detachFlipButtons();
	attach(playerInitials);
	string levelString = "Choose Level";
	redraw();
}
