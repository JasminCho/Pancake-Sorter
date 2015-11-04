//pancake sorter

#include "PancakeSorter.h"

PancakeSorter::PancakeSorter(Point xy, int w, int h, const string& title)
	:Simple_window{xy,w,h,title}
	{
		attach(start);
	}

void PancakeSorter::cb_start(Address, Address window)
{
	reference_to<PancakeSorter>(window).startGame();
}

void PancakeSorter::startGame()
{
	start.hide();
}

