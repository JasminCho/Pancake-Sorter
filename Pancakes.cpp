//Pancake class
//Sorting, vectors, flipping, etc.
//everything related to pancakes

#include "PancakeSorter.h"

void PancakeSorter::addPancake(int y, int w)
{
	Color PANCAKE_COLOR(fl_rgb_color(0xD6, 0xC9, 0x65));
	Ellipse *p = new Ellipse{Point{CENTER_X, y}, w, PANCAKE_HEIGHT};
	p->set_fill_color(PANCAKE_COLOR);
	pancakes.push_back(p);
}

void PancakeSorter::detachPancakes()
{
	for(int i = 0; i < pancakes.size(); i++)
	{
		detach(*pancakes[i]);
	}
}

void PancakeSorter::clearPancakes()
{
	for(int i = 0; i < pancakes.size(); i++)
	{
		detach(*pancakes[i]);

		// delete the pancake ellipse from memory
		delete pancakes[i];
	}

	// clear the pancakes vector
	pancakes.erase(pancakes.begin(), pancakes.end());
}

void PancakeSorter::shufflePancakes()
{
	// save current timestamp
	uint timestamp = time(NULL);
	// seed random with saved time stamp
	srand(timestamp);
	// shuffle pancake ellipses
	random_shuffle(pancakes.begin(), pancakes.end());
	// reseed random generator with the same seed value as before
	// this will give the same "random" sequence, so the vector<Ellipse*> will match the vector<int>
	srand(timestamp);
	// shuffle the pancake position vector in the same sequence as the ellipses
	random_shuffle(pancakePos.begin(), pancakePos.end());

	for(int i = 0; i < getNumPancakes(); i++)
	{
		// moving the pancake ellipse to the initial location
		int newY = (i * Y_DISTANCE * -1);
		pancakes[i]->move(0, newY);
	}
}

void PancakeSorter::flipPancake(int clickedPos)
{
	int clickedIndex = getNumPancakes() - clickedPos;

	cout << "clickedIndex = " << clickedIndex << endl;
	cout << "clickedPos = " << clickedPos << endl;

	reverse(pancakes.end() - clickedPos, pancakes.end());
	reverse(pancakePos.begin(), pancakePos.begin() + clickedPos);

	cout << "Flipping from position: " << clickedPos << endl;

	int topIndex = getNumPancakes() - 1;
	int botIndex = getNumPancakes() - clickedPos;
	int numFlips = clickedPos / 2;

	for(uint i = numFlips; i > 0; i--)
	{
		movePancakes(topIndex, botIndex);
		topIndex--;
		botIndex++;
	}

	redraw();
}

void PancakeSorter::addPancakeEllipses()
{
	for(int i = 0; i < getNumPancakes(); i++)
	{
		addPancake(Y_START, WIDTH_START + (WIDTH_SCALE*i));
	}
}

void PancakeSorter::initializePancakePosition()
{
	for(int i = 0; i < getNumPancakes(); i++)
	{
		// add int to position vector
		pancakePos.push_back(i + 1);
	}
}

void PancakeSorter::movePancakes(int topIndex, int botIndex)
{
	int pancakeDist = topIndex - botIndex;
	int dyTop = pancakeDist * PANCAKE_HEIGHT * -2;
	int dyBot = dyTop * -1;

	cout << "Moving topIndex = " << topIndex << " to " << botIndex << endl;
	cout << "dyTop = " << dyTop << ", dyBot = " << dyBot << endl;

	pancakes[topIndex]->move(0, dyTop);
	pancakes[botIndex]->move(0, dyBot);
}

void PancakeSorter::attachPancakes()
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