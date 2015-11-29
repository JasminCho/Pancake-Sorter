//hiscore.cpp

#include "hiscore.h"

HiScore::HiScore(string name, int s)
{
	playerName = name;
	score = s;
}

string HiScore::toString()
{
	return playerName + " " + to_string(score);
}