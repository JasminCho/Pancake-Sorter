#include <FL/fl_ask.H>
#include "PancakeSorter.h"

//Level Screen

void PancakeSorter::attachLevelScreen()
{
	setLevelBackground();
	setLevelOverlay();
	setLevelText();

	attachLevelButtons();
	attachLevelBackground();
	attachLevelOverlay();
	attachLevelText();

	displayScores();

	redraw();
}

void PancakeSorter::detachLevelScreen()
{
	detachLevelButtons();
	detachLevelBackground();
	detachLevelOverlay();
}

void PancakeSorter::attachLevelButtons()
{
	attach(start);
	attach(two);
	attach(three);
	attach(four);
	attach(five);
	attach(six);
	attach(seven);
	attach(eight);
	attach(nine);
	attach(ten);
	attach(eleven);
	attach(twelve);
}

void PancakeSorter::detachLevelButtons()
{
	detach(start);
	detach(two);
	detach(three);
	detach(four);
	detach(five);
	detach(six);
	detach(seven);
	detach(eight);
	detach(nine);
	detach(ten);
	detach(eleven);
	detach(twelve);
}

void PancakeSorter::attachLevelBackground()
{
	attach(bgLevel1);
	attach(bgLevel2);
	attach(bgLevel3);
	attach(bgLevel4);	
}

void PancakeSorter::setLevelBackground()
{
	bgLevel1.set_fill_color(fl_rgb_color(255,255,0));
	bgLevel2.set_fill_color(fl_rgb_color(255,255,0));
	bgLevel3.set_fill_color(fl_rgb_color(255,255,0));
	bgLevel4.set_fill_color(fl_rgb_color(255,255,0));
	bgLevel1.set_color(fl_rgb_color(255,255,0));
	bgLevel2.set_color(fl_rgb_color(255,255,0));
	bgLevel3.set_color(fl_rgb_color(255,255,0));
	bgLevel4.set_color(fl_rgb_color(255,255,0));
}

void PancakeSorter::detachLevelBackground()
{
	detach(bgLevel1);
	detach(bgLevel2);
	detach(bgLevel3);
	detach(bgLevel4);
}

void PancakeSorter::attachLevelOverlay()
{
	attach(twoRect);
	attach(threeRect);
    attach(fourRect);
    attach(fiveRect);
    attach(sixRect);
    attach(sevenRect);
    attach(eightRect);
    attach(nineRect);
    attach(tenRect);
	attach(elevenRect);
    attach(twelveRect);
	attach(startRect);
}

void PancakeSorter::setLevelOverlay()
{
	twoRect.set_fill_color(fl_rgb_color(50,205,50));
	threeRect.set_fill_color(fl_rgb_color(50,205,50));
	fourRect.set_fill_color(fl_rgb_color(50,205,50));
	fiveRect.set_fill_color(fl_rgb_color(50,205,50));
	sixRect.set_fill_color(fl_rgb_color(50,205,50));
	sevenRect.set_fill_color(fl_rgb_color(50,205,50));
	eightRect.set_fill_color(fl_rgb_color(50,205,50));
	nineRect.set_fill_color(fl_rgb_color(50,205,50));
	tenRect.set_fill_color(fl_rgb_color(50,205,50));
	elevenRect.set_fill_color(fl_rgb_color(50,205,50));
	twelveRect.set_fill_color(fl_rgb_color(50,205,50));
	startRect.set_fill_color(fl_rgb_color(50,205,50));
}

void PancakeSorter::detachLevelOverlay()
{
	detach(twoRect);
    detach(threeRect);
    detach(fourRect);
    detach(fiveRect);
    detach(sixRect);
    detach(sevenRect);
    detach(eightRect);
    detach(nineRect);
    detach(tenRect);
    detach(elevenRect);
    detach(twelveRect);
	detach(startRect);
}

void PancakeSorter::attachLevelText()
{
	attach(playerInitials);
    attach(levelText);
    attach(initialsPrompt);	
	attach(twoText);
    attach(threeText);
    attach(fourText);
    attach(fiveText);
    attach(sixText);
    attach(sevenText);
    attach(eightText);
    attach(nineText);
    attach(tenText);
    attach(elevenText);
    attach(twelveText);
	attach(startText);
	attach(top5);
	attach(top5_1);
	attach(top5_2);
	attach(top5_3);
	attach(top5_4);
	attach(top5_5);
}

void PancakeSorter::setLevelText()
{
	levelText.set_label("Choose Level");
	levelText.set_font(Graph_lib::Font::screen_bold);
	levelText.set_font_size(20);
	top5.set_font(Graph_lib::Font::screen_bold);
	top5.set_font_size(25);
	initialsPrompt.set_font(Graph_lib::Font::screen_bold);
	initialsPrompt.set_font_size(15);
}

void PancakeSorter::detachLevelText()
{
	detach(playerInitials);
	detach(levelText);
	detach(initialsPrompt);
	detach(twoText);
    detach(threeText);
    detach(fourText);
    detach(fiveText);
    detach(sixText);
    detach(sevenText);
    detach(eightText);
    detach(nineText);
    detach(tenText);
    detach(elevenText);
    detach(twelveText);
    detach(startText);
    detach(top5);
	detach(top5_1);
	detach(top5_2);
	detach(top5_3);
	detach(top5_4);
	detach(top5_5);
}

void PancakeSorter::setLevel(int lvl)
{
	level = lvl;
	cout << "Number of Pancakes this level: " << getNumPancakes() << endl;
	string levelString = "Level " + to_string(lvl);
	levelText.set_label(levelString);

	redraw();
}

bool PancakeSorter::checkInitials() //checks if initials are letters 
{
	if(getPlayerInitials() == "")
	{
		fl_alert("You must enter your initials");
		return false;
	}
	else
	{
		// check if initials are only letters
		string name = getPlayerInitials();
		const int ASCII_UPPER_A = 65;
		const int ASCII_UPPER_Z = 90;
		for(uint i = 0; i < name.size(); i++)
		{
			// only need to check A-Z, because getPlayerInitials() returns all caps
			if(name[i] < ASCII_UPPER_A || name[i] > ASCII_UPPER_Z)
			{
				fl_alert("Initials must be letters (A-Z)");
				return false;
			}
		}
	}
	return true;
}

bool PancakeSorter::checkErrors() // checks if initials and level were correctly done
{
	if(level == 0)
	{
 		fl_alert("You must select a level");
 		return false;
	}
	else {
		return checkInitials();
	}
}

