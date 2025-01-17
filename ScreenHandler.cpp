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

	   for (int i = 120; i > 0; i--) {

		
	   }


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
	int nodesRows=1, nodesCol=1;
	for (int i = 0; i < Hmap.getAllAlarms().size(); i++) {

		std::shared_ptr<AlarmNode> alarm = std::make_shared<AlarmNode>();;
		
		alarm->setbackendAlarmClock(&Hmap.getAllAlarms().at(i).clock);
		
	
		std::cout << "AlarmNode Generated\n";
		alarm->setPosition(nodesCol*300, nodesRows * 50);		///REDO GRID RENDERING
		
		gui.add(alarm);
		nodesCol++;
		if (nodesCol > 4) {
			nodesRows++;
			nodesCol = 1;
		}
		
	}
	
}

sf::RectangleShape ScreenHandler::updateTimerFill(long remainingSeconds)
{
	int progress = remainingSeconds / 100;
	int backgroundHeight = 762 * progress;  ///Replace 762 by screen Height according to screen;

	sf::RectangleShape backgroundFill;
	backgroundFill.setFillColor(sf::Color(52,64,75));
	backgroundFill.setSize(sf::Vector2f(2000, backgroundHeight));   //////DIRTY CODE: Figure out a way to get screen width, this is Crap.

	return backgroundFill;
	
}






////Whith your Feet on the Air 
////And you head on the Ground
////Try this trick and spin it
////Your Head Will Colapse if there is nothing in it 
////And You'll ask yourself... 
////Where is My Mind
////Where is My Mind 
////Where is My Mind......