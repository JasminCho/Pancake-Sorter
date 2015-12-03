//pancake sorter
#include <FL/fl_ask.H>
#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Simple_window{xy,w,h,title}
	{
		loadScores();
		attachSplash();
	}
// Splash Screen
void PancakeSorter::attachSplash()
{
	setSplashScreen();

	// Texts
	attach(bgcolor);
	attach(gameTitle);
	attach(teamNumber);
	attach(bl);
	attach(jc);
	attach(jg);

	// Buttons
	attach(instructRect);
	attach(instructLabel);
	attach(instructButton);
	attach(levelScreenRect);
	attach(levelScreenLabel);
	attach(levelScreenButton);
	picAttach();
}

void PancakeSorter::detachSplash()
{
	detach(mainPancakePic);
	detach(sidePancakePic1);
	detach(sidePancakePic2);
	detach(bgcolor);
	detach(gameTitle);
	detach(teamNumber);
	detach(bl);
	detach(jc);
	detach(jg);
	detach(instructRect);
	detach(instructLabel);
	detach(instructButton);
	detach(levelScreenRect);
	detach(levelScreenLabel);
	detach(levelScreenButton);
}

void PancakeSorter::setSplashScreen()
{
    bgcolor.set_fill_color(fl_rgb_color(16,179,122));
	gameTitle.set_font(Graph_lib::Font::screen_bold);
	gameTitle.set_font_size(50);
	teamNumber.set_font_size(35);
	bl.set_font_size(30);
	jc.set_font_size(30);
	jg.set_font_size(30);
	instructRect.set_fill_color(Color::white);
	instructRect.set_color(Color::invisible);
	instructLabel.set_font(Graph_lib::Font::screen_bold);
	levelScreenRect.set_fill_color(Color::white);
	levelScreenRect.set_color(Color::invisible);
	levelScreenLabel.set_font(Graph_lib::Font::screen_bold);
}

void PancakeSorter::picAttach()
{
    attach(mainPancakePic);
    attach(sidePancakePic1);
    attach(sidePancakePic2);
}

void PancakeSorter::startFromSplash()
{
	detachSplash();
	attachLevelScreen();
}

// Instructions Screen
void PancakeSorter::attachInstruct()
{
	detachSplash();
	
	setInstruct();

	attach(bgcolor);
	attach(instTitle);
	attach(lineOne);
	attach(lineTwo);
	attach(lineThree);
	attach(lineFour);
	attach(lineFive);
	attach(lineSix);
	attach(instToLevelRect);
	attach(instToLevelLabel);
	attach(instToLevelButton);
	
	redraw();
}

void PancakeSorter::setInstruct()
{
	bgcolor.set_fill_color(fl_rgb_color(30,216,230));
	instTitle.set_font(Graph_lib::Font::screen_bold);
	instTitle.set_font_size(30);
	lineOne.set_font_size(20);
	lineTwo.set_font_size(20);
	lineThree.set_font_size(20);
	lineFour.set_font_size(20);
	lineFive.set_font_size(20);
	lineSix.set_font_size(20);
	instToLevelRect.set_fill_color(Color::white);
	instToLevelRect.set_color(Color::invisible);
	instToLevelLabel.set_font(Graph_lib::Font::screen_bold);
}

void PancakeSorter::detachInstruct()
{
	detach(bgcolor);
	detach(instTitle);
	detach(lineOne);
	detach(lineTwo);
	detach(lineThree);
	detach(lineFour);
	detach(lineFive);
	detach(lineSix);
	detach(instToLevelRect);
	detach(instToLevelLabel);
	detach(instToLevelButton);
}

void PancakeSorter::startFromInstruct()
{
	detachInstruct();
	detach(instToLevelButton);
	attachLevelScreen();
	redraw();
}