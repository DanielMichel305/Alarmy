#pragma once

#include <TGUI/TGUI.hpp>


#include "HashAlarm.h" 

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
};

