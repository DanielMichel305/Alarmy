#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "AlarmNode.h"
#include "ScreenHandler.h"
	



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
	alarm2.setAlarmTime(17, 10, 0);
	alarm2.setDaysToRing(arr);

	hmap.insertQuadratic(alarm1.hash()%hmap.getCapacity(), alarm1);
	hmap.insertQuadratic(alarm2.hash() % hmap.getCapacity(), alarm2);

	
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

		
		

		win.clear();
		win.draw(background);
		win.draw(sideBar);

		gui.draw();

		win.display();


	}
	

}