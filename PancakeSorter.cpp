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
	}

void PancakeSorter::cb_start(Address, Address window)
{
	reference_to<PancakeSorter>(window).startGame();
}

void PancakeSorter::cb_two(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(2);
}

void PancakeSorter::cb_three(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(3);
}

void PancakeSorter::cb_four(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(4);
}

void PancakeSorter::cb_five(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(5);
}

void PancakeSorter::cb_six(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(6);
}

void PancakeSorter::cb_seven(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(7);
}

void PancakeSorter::cb_eight(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(8);
}

void PancakeSorter::cb_nine(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(9);
}

void PancakeSorter::cb_ten(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(10);
}

void PancakeSorter::cb_eleven(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(11);
}

void PancakeSorter::cb_twelve(Address, Address window)
{
	reference_to<PancakeSorter>(window).level(12);
}

void PancakeSorter::level(int lvl)
{
	switch(lvl)
	{
		case 2:
			cout << "2 pancakes\n";
			break;
		case 3:
			cout << "3 pancakes\n";
			break;
		case 4:
			cout << "4 pancakes\n";
			break;
		case 5:
			cout << "5 pancakes\n";
			break;
		case 6:
			cout << "6 pancakes\n";
			break;
		case 7:
			cout << "7 pancakes\n";
			break;
		case 8:
			cout << "8 pancakes\n";
			break;
		case 9:
			cout << "9 pancakes\n";
			break;
		case 10:
			cout << "10 pancakes\n";
			break;
		case 11:
			cout << "11 pancakes\n";
			break;
		case 12:
			cout << "12 pancakes\n";
			break;
	}
}

void PancakeSorter::startGame()
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

