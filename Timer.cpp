#include "PancakeSorter.h"

void PancakeSorter::setupTimer()
{
	timerEnabled = true;

	timeLeft = getNumPancakes() * 10;
	timerText.set_font_size(22);
	timerText.set_label("Time: " + to_string(timeLeft));
	Fl::add_timeout(1, cb_timer, (void*)this);
}

void PancakeSorter::stopTimer()
{
	// stop the game timer
	timerEnabled = false;
	detach(timerText);
	Fl::remove_timeout(cb_timer);
}

void PancakeSorter::decreaseTimer()
{
	// decrease timer by 1 second
	timeLeft--;
	timerText.set_label("Time: " + to_string(timeLeft));
	cout << "Time: " << timeLeft << endl;

	// if time is negative or 0, game is over
	if(timeLeft <= 0)
	{
		gameLose();
		return;
	}
	else
	{
		// there is still time, add the timeout again
		if(timerEnabled)
		{
			Fl::add_timeout(1, cb_timer, (void*)this);
			redraw();
		}
	}
}

void PancakeSorter::cb_timer(void* win)
{
	PancakeSorter* window = static_cast<PancakeSorter*>(win);
	window->decreaseTimer();
}