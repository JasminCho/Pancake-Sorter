//Buttons.cpp
#include "PancakeSorter.h"

//Call backs setting the level for the pancake numbers
void PancakeSorter::cb_instruct(Address, Address window)
{
	reference_to<PancakeSorter>(window).startInstruct();
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

void PancakeSorter::setLevel(int lvl)
{
	level = lvl;
	cout << "Number of Pancakes this level: " << getNumPancakes() << endl;
	string levelString = "Level " + to_string(lvl);
	levelText.set_label(levelString);

	redraw();
}
//Pancake Flipping cb
void PancakeSorter::cb_flip2(Address,Address window)
{
    cout<<"flip 2\n";
}
void PancakeSorter::cb_flip3(Address,Address window)
{
    cout<<"flip 3\n";
}
void PancakeSorter::cb_flip4(Address,Address window)
{
    cout<<"flip 4\n";
}
void PancakeSorter::cb_flip5(Address,Address window)
{
    cout<<"flip 5\n";
}
void PancakeSorter::cb_flip6(Address,Address window)
{
    cout<<"flip 6\n";
}
void PancakeSorter::cb_flip7(Address,Address window)
{
    cout<<"flip 7\n";
}
void PancakeSorter::cb_flip8(Address,Address window)
{
    cout<<"flip 8\n";
}
void PancakeSorter::cb_flip9(Address,Address window)
{
    cout<<"flip 9\n";
}
void PancakeSorter::cb_flip10(Address,Address window)
{
    cout<<"flip 10\n";
}
void PancakeSorter::cb_flip11(Address,Address window)
{
    cout<<"flip 11\n";
}
void PancakeSorter::cb_flip12(Address,Address window)
{
    cout<<"flip 12\n";
}
