//Pancake class
//Sorting, vectors, flipping, etc.
//everything related to pancakes

#include "PancakeSorter.h"
#include "HintFlash.h"

Color PancakeSorter::getPancakeColor()
{
	//Random values for RGB of pancake color
	//In order to make pancakes of different colors
	vector<int> v;
	for(int i=0;i<=255;++i)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(),v.end());
	int r=v[0];
	random_shuffle(v.begin(),v.end());
	int g=v[0];
	random_shuffle(v.begin(),v.end());
	int b=v[0];
	Color PANCAKE_COLOR(fl_rgb_color(r,g,b));
	return PANCAKE_COLOR;
}

void PancakeSorter::addPancake(int y, int w)
{
	Ellipse *p = new Ellipse{Point{CENTER_X, y}, w, PANCAKE_HEIGHT};
	p->set_fill_color(getPancakeColor());
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
	// reverse the position vector because it's inverted
	reverse(pancakePos.begin(), pancakePos.end());

	for(int i = 0; i < getNumPancakes(); i++)
	{
		// moving the pancake ellipse to the initial location
		int newY = (i * Y_DISTANCE * -1);
		pancakes[i]->move(0, newY);
	}

	cout << "shuffled pancakes: ";
	for(uint i = 0; i < pancakePos.size(); i++)
	{
		cout << pancakePos[i] << ", ";
	}
	cout << endl;
}

void PancakeSorter::flipPancake(int clickedPos)
{
	int clickedIndex = getNumPancakes() - clickedPos;

	reverse(pancakes.end() - clickedPos, pancakes.end());
	reverse(pancakePos.begin(), pancakePos.begin() + clickedPos);

	int topIndex = getNumPancakes() - 1;
	int botIndex = getNumPancakes() - clickedPos;
	int numFlips = clickedPos / 2;

	for(uint i = numFlips; i > 0; i--)
	{
		movePancakes(topIndex, botIndex);
		topIndex--;
		botIndex++;
	}

	setMoves(moves+1);

	// calculate score
	calcScore();
	calcWinLose();

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

// highlight the pancake in a neon green border
void PancakeSorter::hintFlashStart(void* hf)
{
	// HintFlash is a class that has 2 pointers
	// One points to the PancakeSorter window class for redraw() and getPancakeColor()
	// Another points to an ellipse which is the pancake that should be flashed
	HintFlash* instance = static_cast<HintFlash*>(hf);
	const Color NEON_GREEN = fl_rgb_color(57, 255, 20);

	instance->pancake->set_style(Line_style(Line_style::solid, 6));
	instance->pancake->set_color(NEON_GREEN);
	instance->window->redraw();

	// delete the HintFlash instance
	delete instance;
}

// reset the border back to normal
void PancakeSorter::hintFlashEnd(void* hf)
{
	// HintFlash is a class that has 2 pointers
	// One points to the PancakeSorter window class for redraw() and getPancakeColor()
	// Another points to an ellipse which is the pancake that should be flashed
	HintFlash* instance = static_cast<HintFlash*>(hf);
	Color newColor = instance->window->getPancakeColor();

	instance->pancake->set_style(Line_style(Line_style::solid, 1));
	instance->pancake->set_fill_color(newColor);
	instance->pancake->set_color(Color::black);
	instance->window->redraw();

	// delete the HintFlash instance
	delete instance;
}

void PancakeSorter::hint()
{
	vector<int>* solution = getSolution();

	// ellipses are drawn from bottom up, so 0 is at the bottom
	int nextFlipIndex = getNumPancakes() - solution->at(0);

	if(getNumPancakes() > 9)
	{
		nextFlipIndex--;
	}

	// get a pointer to the hinted pancake ellipse
	Ellipse* nextPancake = pancakes[nextFlipIndex];

	// flash the next best move in neon green 3 times
	for(int i = 0; i < 4; i++) {
		HintFlash *start = new HintFlash(this, nextPancake);
		HintFlash *end = new HintFlash(this, nextPancake);

		Fl::add_timeout(0.5 + i, hintFlashStart, (void*)start);
		Fl::add_timeout(1.0 + i, hintFlashEnd, (void*)end);
	}
}

// returns an all-caps version of the entered player initials
string PancakeSorter::getPlayerInitials()
{
	string str = playerInitials.get_string();
	for(int i = 0; i < str.size(); i++)
	{
	    str[i] = toupper(str[i]);
	}
	return str;
}
