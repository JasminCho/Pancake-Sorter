//main.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "PancakeSorter.h"

int main()
{
	PancakeSorter window(Point(300,100),1000,800,"Flip Flaps Game");

	window.wait_for_button();
}