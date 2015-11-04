//main.cpp

#include "std_lib_facilities_4.h"
#include "Window.h"
#include "Graph.h"
#include "PancakeSorter.h"

int main()
{
	PancakeSorter window(Point(200,200),1000,1000,"Flip Flaps");

	window.wait_for_button();
}