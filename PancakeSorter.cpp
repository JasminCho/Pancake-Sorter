//pancake sorter

#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Simple_window{xy,w,h,title}
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
		
		attach(gameTitle);
		attach(levelText);
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

