//Buttons.cpp
#include "PancakeSorter.h"

//Call backs setting the level for the pancake numbers
void PancakeSorter::cb_instruct(Address, Address window)
{
	reference_to<PancakeSorter>(window).startInstruct();
}
void PancakeSorter::cb_instructToLevel(Address, Address window)
{
	reference_to<PancakeSorter>(window).startFromInstruct();
}
void PancakeSorter::cb_levelScreen(Address, Address window)
{
	reference_to<PancakeSorter>(window).showLevel();
}

void PancakeSorter::cb_start(Address, Address window)
{
	reference_to<PancakeSorter>(window).startGame();
}

void PancakeSorter::cb_two(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(2);
}

void PancakeSorter::cb_three(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(3);
}

void PancakeSorter::cb_four(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(4);
}

void PancakeSorter::cb_five(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(5);
}

void PancakeSorter::cb_six(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(6);
}

void PancakeSorter::cb_seven(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(7);
}

void PancakeSorter::cb_eight(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(8);
}

void PancakeSorter::cb_nine(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(9);
}

void PancakeSorter::cb_ten(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(10);
}

void PancakeSorter::cb_eleven(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(11);
}

void PancakeSorter::cb_twelve(Address, Address window)
{
	reference_to<PancakeSorter>(window).setLevel(12);
}

void PancakeSorter::cb_exitGame(Address, Address window)
{
	reference_to<PancakeSorter>(window).exitGame();
}

void PancakeSorter::cb_back(Address, Address window)
{
	reference_to<PancakeSorter>(window).back();
}

void PancakeSorter::cb_flip11(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes());
}

void PancakeSorter::cb_flip10(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 1);
}

void PancakeSorter::cb_flip9(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 2);
}

void PancakeSorter::cb_flip8(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 3);
}

void PancakeSorter::cb_flip7(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 4);
}

void PancakeSorter::cb_flip6(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 5);
}

void PancakeSorter::cb_flip5(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 6);
}

void PancakeSorter::cb_flip4(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 7);
}

void PancakeSorter::cb_flip3(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 8);
}

void PancakeSorter::cb_flip2(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 9);
}

void PancakeSorter::cb_flip1(Address, Address window)
{
	PancakeSorter &win = reference_to<PancakeSorter>(window);
	win.flipPancake(win.getNumPancakes() - 10);
}

void PancakeSorter::cb_hint(Address, Address window)
{
	reference_to<PancakeSorter>(window).hint();
}
