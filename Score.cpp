//score.cpp

#include "find_solution.h"
#include "PancakeSorter.h"

void PancakeSorter::outputInitials()
{
	string player = getPlayerInitials();
}

void PancakeSorter::newHiScore()
{
	HiScore myScore(getPlayerInitials(), playerScore);
	scores.push_back(myScore);

	sortHiScores();
}

void PancakeSorter::sortHiScores()
{
	sort(scores.begin(), scores.end(), HiScoreSorter());
}

void PancakeSorter::saveScores()
{
	ofstream out;
	out.open("hiscores.txt");

	for(uint i = 0; i < scores.size() && i < 5; i++)
	{
		out << scores[i].toString() << "\r\n";
	}

	out.close();
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

		if(name != "")
		{
			scores.push_back(HS1);
		}
	}

	in.close();
}

void PancakeSorter::displayScores()
{
	// show top 5 hi scores
	displayScores(top5_1, 0);
	displayScores(top5_2, 1);
	displayScores(top5_3, 2);
	displayScores(top5_4, 3);
	displayScores(top5_5, 4);
}

void PancakeSorter::displayScores(Text &text, int index)
{
	if(scores.size() >= index + 1) { text.set_label(scores[index].toString()); }
}

void PancakeSorter::setMoves(int newMoves)
{
	moves = newMoves;
	movesText.set_label("Moves: " + to_string(moves));
}

vector<int>* PancakeSorter::getSolution()
{
	vector<int>* solution = m_find_solution(pancakePos);
	return solution;
}

void PancakeSorter::calcMinMoves()
{
	vector<int>* solution = getSolution();
	minMoves = num_moves(solution);
	minMovesText.set_label("Can be done in " + to_string(minMoves) + " flips");
}

void PancakeSorter::calcScore()
{
	if(pancakePos.size() > 0)
	{
	 	setPlayerScore((100 - 10 * (moves - minMoves)) * getNumPancakes());
		scoreText.set_label("Score: " + to_string(playerScore));
	}
}

void PancakeSorter::setPlayerScore(int newScore)
{
	playerScore = newScore;
	scoreText.set_label("Score: " + to_string(playerScore));
}

void PancakeSorter::calcWinLose()
{
	vector<int>* solution = getSolution();
	int movesLeft = num_moves(solution);

	if(playerScore <= 0)
	{
		attachEndScreen();
		gameLose();
	}
	else if(movesLeft == 0)
	{
		attachEndScreen();
		gameWin();
	}
}
