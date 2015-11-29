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

struct HiScoreSorter
{
    inline bool operator() (const HiScore& score1, const HiScore& score2)
    {
        return (score1.score > score2.score);
    }
};