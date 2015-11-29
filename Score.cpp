//score.cpp

#include "find_solution.h"
#include "PancakeSorter.h"

void PancakeSorter::outputInitials()
{
	string player = playerInitials.get_string();
	cout << player << endl;
}

void PancakeSorter::loadScores()
{
	string name = "";
	int score = 0;
	ifstream in;
	in.open("hiscores.txt");
	while(in.good())
	{
		in >> name >> score;
		HiScore HS1(name, score);
		scores.push_back(HS1);
	}

	for(uint i = 0; i < scores.size(); i++)
	{
		cout << scores[i].playerName << " " << scores[i].score << endl;
	}
}

void PancakeSorter::calcScore(int numFlips, int timeLeft)
{
	vector<int>* solution = m_find_solution(pancakePos);
	int minFlips = num_moves(solution);

	int playerScore = (100 - 10 * (numFlips - minFlips)) * getNumPancakes();
	// if(playerScore = 0)
	// {
	// 	return gameOver;
	// }
	// else if(playerScore > )
}
