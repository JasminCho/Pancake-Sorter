
#include "find_solution.h"

//Input: A vector<int> representing a stack of n pancakes numbered 1 to n in
//	any order, with the top pancake in element [0]; 2 <= n <= 9.

//Output: If the input argument is invalid, return nullptr;
//	otherwise, return a vector<int>*, where the vector<int> contains the
//	sequence of flips to put the stack of pancakes into order.  For example,
//	if the input is {4,1,2,3}, meaning the top pancake is 4, the output will
//	be a pointer to {4,3}, meaning flip the top 4 (giving {3,2,1,4}) and
//	then flip the top 3 (giving {1,2,3,4}).  The size of the vector is 2,
//	which is the minimum number of flips to put the pancakes in order.  This
//	minimum is to be used in the scoring function, and to determine when to
//	stop the game for too many flips.

int find_pancake(int pancake, const vector<int>& pancakes)
{
	// get the index of the specific pancake
	uint index = find(pancakes.begin(), pancakes.end(), pancake) - pancakes.begin();
	if(index >= pancakes.size())
	{
		return -1;
	}

	return index;
}

vector<int>* student_solution(const vector<int>& originalPancakes)
{
	vector<int> pancakes = vector<int>(originalPancakes);
	vector<int>* solution = new vector<int>();
	

	for(int num = pancakes.size(); num > 0; num--)
	{
		// where num was found in the pancake stack
		int currentLocation = find_pancake(num, pancakes);
		// where the pancake should be if it was in the correct spot
		int correctLocation = num - 1;
		cout  << num << " is at " << currentLocation << ", should be at " << correctLocation << endl;

		// if not already in the correct spot
		if(currentLocation != 0 && currentLocation != correctLocation)
		{
			// flip from current location
			solution->push_back(currentLocation);
			reverse(pancakes.begin(), pancakes.begin() + currentLocation);
			// advance current location to the top
			currentLocation = 0;
		}
		if(currentLocation == 0 && correctLocation != 0)
		{
			// flip from correct location to put it from the top to the correct spot
			solution->push_back(correctLocation);
			reverse(pancakes.begin(), pancakes.begin() + correctLocation);
		}
	}

	return solution;
}

vector<int>* m_find_solution(const vector<int>& pancakes)
{
	// error checking
	if(pancakes.size() < 2 || pancakes.size() > 12) { return nullptr; }
	
	if(pancakes.size() <= 9)
	{
		// use instructor solution for the first 9
		vector<int>* instructor_solution = find_solution(pancakes);
		return instructor_solution;
	}
	else
	{
		// use our solution for 10-12
		vector<int>* solution = student_solution(pancakes);
		return solution;
	}
}


int num_moves(const vector<int> *solution)
{
	int moves = solution->size();
	return moves;
}