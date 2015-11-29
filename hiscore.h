//hiscore.h

#include "std_lib_facilities_4.h"

class HiScore
{
public:
	HiScore(string name, int s);
	string toString();

	string playerName = "";
	int score = 0;
};