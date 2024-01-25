#include "ScreenHandler.h"

int ScreenHandler::ScreenState = -1;

ScreenHandler::ScreenHandler()
{
   // ScreenState = -1;
}

int ScreenHandler::getScreenState()
{
    return ScreenState;
}

void ScreenHandler::setScreenState(tgui::GuiSFML& gui, int screenState)
{
   
    if (screenState == -1) {
        ///Clear screen

        gui.removeAllWidgets();
        ScreenState = -1;

    }
    else if (screenState == 1) {
        ///Render Alarm Screen 
        ScreenState = 1;
		std::cout << "Alarm Screen \n";

		



    }
    else if (screenState == 2) {
        ///Render Timer Screen
       ScreenState = 2;
	   std::cout << "Timer Screen \n";
    }
    else if (screenState == 3) {
        ///Render Stopwatch Screen
        ScreenState = 3;
		std::cout << "Stopwatch Screen \n";
    }
    std::cout << screenState <<"\n";
}

void ScreenHandler::createSideBar(sf::RenderWindow &win,tgui::GuiSFML& gui)
{
	tgui::Panel::Ptr sideBarPanel = tgui::Panel::create();
	sideBarPanel->setSize(win.getSize().x * 0.2, 300);
	sideBarPanel->getRenderer()->setBackgroundColor(sf::Color(2, 17, 31));

	tgui::Button::Ptr AlarmButton = tgui::Button::create("Alarms");
	AlarmButton->setPosition(10, 50);
	AlarmButton->setSize(255, 43);
	AlarmButton->getRenderer()->setTextColor(sf::Color(230, 230, 250));
	AlarmButton->getRenderer()->setTextColorHover(sf::Color(230, 230, 250));
	AlarmButton->getRenderer()->setTextColorDown(sf::Color(230, 230, 250));
	AlarmButton->getRenderer()->setRoundedBorderRadius(10);
	AlarmButton->getRenderer()->setBackgroundColor(sf::Color(52, 64, 75));
	AlarmButton->getRenderer()->setBackgroundColorHover((sf::Color(52, 64, 75)));

	AlarmButton->onClick([&] {
		setScreenState(gui, 1);
		
		});



	tgui::Button::Ptr TimerButton = tgui::Button::create("Timer");
	TimerButton->setPosition(10, TimerButton->getSize().y + AlarmButton->getPosition().y + 30);
	TimerButton->setSize(255, 43);
	TimerButton->getRenderer()->setTextColor(sf::Color(230, 230, 250));
	TimerButton->getRenderer()->setTextColorHover(sf::Color(230, 230, 250));
	TimerButton->getRenderer()->setTextColorDown(sf::Color(230, 230, 250));
	TimerButton->getRenderer()->setRoundedBorderRadius(10);
	TimerButton->getRenderer()->setBackgroundColor(sf::Color(52, 64, 75));
	TimerButton->getRenderer()->setBackgroundColorHover((sf::Color(52, 64, 75)));

	TimerButton->onClick([&] {
		setScreenState(gui, 2);

		});

	tgui::Button::Ptr stopwatchButton = tgui::Button::create("Stopwatch");
	stopwatchButton->setPosition(10, stopwatchButton->getSize().y + TimerButton->getPosition().y + 30);
	stopwatchButton->setSize(255, 43);
	stopwatchButton->getRenderer()->setTextColor(sf::Color(230, 230, 250));
	stopwatchButton->getRenderer()->setTextColorHover(sf::Color(230, 230, 250));
	stopwatchButton->getRenderer()->setTextColorDown(sf::Color(230, 230, 250));
	stopwatchButton->getRenderer()->setRoundedBorderRadius(10);
	stopwatchButton->getRenderer()->setBackgroundColor(sf::Color(52, 64, 75));
	stopwatchButton->getRenderer()->setBackgroundColorHover((sf::Color(52, 64, 75)));

	stopwatchButton->onClick([&] {
		setScreenState(gui, 3);

		});



	sideBarPanel->add(AlarmButton);
	sideBarPanel->add(TimerButton);
	sideBarPanel->add(stopwatchButton);
	gui.add(sideBarPanel);
}

void ScreenHandler::GenerateAlarmNode(tgui::GuiSFML& gui, HashAlarm Hmap)
{
	
	for (int i = 0; i < Hmap.getAllAlarms().size(); i++) {

		//std::shared_ptr<AlarmNode> alarm = AlarmNode(Hmap.getAllAlarms().at(i).clock);

		std::shared_ptr<AlarmNode> alarm;
		std::cout << Hmap.getAllAlarms().at(i).clock.getDaysToRing()[3];
		alarm->setbackendAlarmClock(Hmap.getAllAlarms().at(i).clock);

		
		 //alarm = AlarmNode(Hmap.getAllAlarms().at(i).clock);
		std::cout << "AlarmNode Generated\n";
		alarm->setPosition(350, i * 50);
		
		gui.add(alarm);
	}
	
}

