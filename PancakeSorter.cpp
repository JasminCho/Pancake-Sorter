//pancake sorter

#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Simple_window{xy,w,h,title}
	{
		startScreen();
	}

void PancakeSorter::startScreen()
{
	//background
	bgcolor.set_fill_color(fl_rgb_color(16,179,122));
	attach(bgcolor);
	attach(mainPancakePic);
	attach(sidePancakePic1);
	attach(sidePancakePic2);
	
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
	attach(instruct);
	instructLabel.set_font(Graph_lib::Font::screen_bold);
	attach(instructLabel);
	attach(instructButton);
	attach(levelScreen);
	levelScreenLabel.set_font(Graph_lib::Font::screen_bold);
	attach(levelScreenLabel);
	attach(levelScreenButton);
	
	
	

}

void PancakeSorter::showLevel()
{
		detachSplash();
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
		redraw();
}

void PancakeSorter::hideButtons()
{
	start.hide();
	
	two.hide();
	three.hide();
	four.hide();
	five.hide();
	six.hide();
	seven.hide();
	eight.hide();
	nine.hide();
	ten.hide();
	eleven.hide();
	twelve.hide();


}

void PancakeSorter::startGame()
{
	detach(levelText);
	
	hideButtons();
	//add pancakes
	setPancakes();
	// attach pancakes
	drawPancakes();

	// attach current Level player chose

	redraw();
}

void PancakeSorter::detachSplash(){
	detach(bgcolor);
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

void PancakeSorter::startInstruct(){
	
	detachSplash();
	

	redraw();
}
