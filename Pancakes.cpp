//Pancake class
//Sorting, vectors, flipping, etc.
//everything related to pancakes

#include "PancakeSorter.h"

void PancakeSorter::addPancake(int y, int w)
{
	Color PANCAKE_COLOR(fl_rgb_color(0xD6, 0xC9, 0x65));
	const int CENTER_X = 500;
	const int PANCAKE_HEIGHT = 20;
	Ellipse *p = new Ellipse{Point{CENTER_X, y}, w, PANCAKE_HEIGHT};
	p->set_fill_color(PANCAKE_COLOR);
	pancakes.push_back(p);
}

void PancakeSorter::setPancakes()
{
	const int Y_START = 700;
	const int WIDTH_START = 50;

	const int Y_DISTANCE = 40;
	const int WIDTH_SCALE = 30;

	for(int i = 0; i < getNumPancakes(); i++)
	{
		addPancake(Y_START - (Y_DISTANCE*i), WIDTH_START + (WIDTH_SCALE*i));
	}
}

void PancakeSorter::drawPancakes()
{
	for(int i = 0; i < pancakes.size(); i++)
	{
		attach(*pancakes[i]);
	}
}

int PancakeSorter::getNumPancakes()
{
	return level;
}