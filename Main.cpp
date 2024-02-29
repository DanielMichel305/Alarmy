#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "AlarmNode.h"
#include "ScreenHandler.h"
	
void checkForAlarms(HashAlarm& clocks)
{

	for (int i = 0; i < clocks.getCapacity(); i++)
	{
		if (clocks.getElementIterator(i).clock.isTimeToRing() && !clocks.getElementIterator(i).clock.getringtoneActive())
		{
			clocks.getElementIterator(i).clock.activateRingtone();
			clocks.getElementIterator(i).setisPlaying(true);
		}
		else if (!clocks.getElementIterator(i).clock.isTimeToRing()) {
			clocks.getElementIterator(i).clock.stopRingtone();
		}
	}
}


int main() {

	ScreenHandler screenHandle;

	sf::RenderWindow win(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Alarm Clock");
	win.setFramerateLimit(60);
	::ShowWindow(win.getSystemHandle(), SW_MAXIMIZE);

	tgui::GuiSFML gui(win);

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(win.getSize().x, win.getSize().y));
	sf::Color backgroundColor;
	backgroundColor = sf::Color(2, 17, 31);
	background.setFillColor(backgroundColor);

	sf::RectangleShape sideBar;
	background.setSize(sf::Vector2f(win.getSize().x * 0.2, win.getSize().y));
	sf::Color sideBarColor;
	sideBarColor = sf::Color(2, 17, 31);
	sideBar.setFillColor(sideBarColor);

	auto alarmNode = std::make_shared<AlarmNode>();
	alarmNode->setPosition(350, 50);
	//gui.add(alarmNode);
	//screenHandle.setScreenState(gui, -1);

	screenHandle.createSideBar(win, gui);

	HashAlarm hmap;
	AlarmClock alarm1;
	alarm1.setAlarmTime(20, 30, 0);
	int arr[] = { 0,1,2,3,4,5,6 };
	alarm1.setDaysToRing(arr);
	
	
	AlarmClock alarm2;

	alarm2.setAlarmTime(11, 49, 0);  //<---
	alarm2.setDaysToRing(arr);
	alarm2.setRingtone("Ringtones\\Radar.ogg");

	AlarmClock alarm3;

	alarm3.setAlarmTime(11, 55, 0);  //<---
	alarm3.setDaysToRing(arr);
	alarm3.setRingtone("Ringtones\\Radar.ogg");

	

	hmap.insertQuadratic(alarm1.hash()%hmap.getCapacity(), alarm1);
	hmap.insertQuadratic(alarm2.hash()%hmap.getCapacity(), alarm2);
	hmap.insertQuadratic(alarm3.hash() % hmap.getCapacity(), alarm3);


	
	screenHandle.GenerateAlarmNode(gui, hmap);

	while (win.isOpen()) {

		sf::Event evt;
		while (win.pollEvent(evt))
		{
			
			if (evt.type == sf::Event::Closed) {
				win.close();
			}
			gui.handleEvent(evt);
		}

		checkForAlarms(hmap);
		

		win.clear();
		win.draw(background);
		win.draw(sideBar);

		gui.draw();

		win.display();


	}
	

}