#pragma once

#include <TGUI/TGUI.hpp>


#include "HashAlarm.h" 
#include "AlarmNode.h"

class ScreenHandler
{
	
private: 
	static int ScreenState;
	int ScreenHeight, ScreenWidth;
	tgui::Gui guiObj;


public:

	ScreenHandler();
	int getScreenState();
	void setScreenState(tgui::GuiSFML &gui, int screenState);
	void createSideBar(sf::RenderWindow &win, tgui::GuiSFML& gui);
	void GenerateAlarmNode(tgui::GuiSFML& gui, HashAlarm Hmap);
	sf::RectangleShape updateTimerFill(long remainingSeconds);
};

