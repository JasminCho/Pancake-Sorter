//Buttons.cpp
#include "PancakeSorter.h"

//Call backs setting the level for the pancake numbers

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

void PancakeSorter::setLevel(int lvl)
{
	cout << "Number of Pancakes this level: " << lvl << endl;
	string levelString = "Level " + to_string(lvl-1);
	levelText.set_label(levelString);
	redraw();
}