//HintFlash.h
// This class just has a pointer to the pancake sorter window, and a pancake ellipse
// Used in the hint() method to pass the window and pancake ellipse to a callback function

#include "PancakeSorter.h"

class HintFlash
{
public:
	HintFlash(PancakeSorter* win, Ellipse* pan);
	
	PancakeSorter* window;
	Ellipse* pancake;
};