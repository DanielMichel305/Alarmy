#include "AlarmNode.h"

AlarmNode::AlarmNode()
{
	setSize(250, 200);
	
	
	sf::Color fillColor(52,64,75);
	getRenderer()->setBackgroundColor(fillColor);
	getRenderer()->setRoundedBorderRadius(10);
	


	alarmActivate = std::make_shared<ToggleSwitch>();
	alarmActivate->setPosition(169, 32);
	
	
	
	alarmActivateLabel = tgui::Label::create();
	alarmActivateLabel->setPosition(alarmActivate->getPosition().x - 85, alarmActivate->getPosition().y);
	alarmActivateLabel->getRenderer()->setTextColor(sf::Color(255, 255, 255));
	

	clockLabel = tgui::Label::create();
	clockLabel->setText("6:30");
	clockLabel->setPosition(14, 13);
	clockLabel->setTextSize(48);
	clockLabel->getRenderer()->setTextColor(sf::Color(255, 255, 255));

	clockDescriptionLabel = tgui::TextArea::create();
	clockDescriptionLabel->setSize(200, 65);
	clockDescriptionLabel->setText("This Is an Alarm Label. Please Wake Up you have Work!");
	clockDescriptionLabel->setPosition(19, 74);
	clockDescriptionLabel->setTextSize(14);
	clockDescriptionLabel->getRenderer()->setTextColor(sf::Color(255, 255, 255));
	clockDescriptionLabel->getRenderer()->setBackgroundColor(sf::Color(52, 64, 75));
	clockDescriptionLabel->getRenderer()->setBorders(tgui::Borders(0, 0, 0, 0));




	for (short i = 0; i < 7; i++) {
		
		dayCheckBox[i] = tgui::CheckBox::create();			
		dayCheckBox[i]->setPosition(14*i+50, 155);
		dayCheckBox[i]->getRenderer()->setBackgroundColor(sf::Color(33, 0, 93));
		dayCheckBox[i]->getRenderer()->setBackgroundColorHover(sf::Color(33, 0, 93));
		dayCheckBox[i]->getRenderer()->setCheckColor(sf::Color(255, 255, 255));
		dayCheckBox[i]->getRenderer()->setCheckColorHover(sf::Color(255, 255, 255));
		


		add(dayCheckBox[i]);
	}

	add(alarmActivateLabel);
	add(alarmActivate);
	add(clockLabel);
	add(clockDescriptionLabel);
}

AlarmNode::AlarmNode(AlarmClock clockObj){
	this->backendAlarmClock = &clockObj;

	AlarmNode();

}

void AlarmNode::setPosition(float x, float y)
{
	tgui::Panel::setPosition(x, y);

	//alarmActivate->setPosition(x + alarmActivate->getPosition().x, y + alarmActivate->getPosition().y);
	alarmActivate->setPosition(210, 32);
	alarmActivateLabel->setPosition(alarmActivate->getPosition().x - 85, alarmActivate->getPosition().y);

	clockLabel->setPosition(14, 13);

	for (short i = 0; i <7; i++) {

		dayCheckBox[i]->setPosition(20+(14 * i)+19*i, 155);
		
	}

}

bool AlarmNode::isAlarmActivated()
{
	return alarmActivate->isToggled();
}

void AlarmNode::UIAlarmActivate(bool status)
{
	///TODO: Add Alarm Backend Functionality
	alarmActivate->setToggled(status);	

}

AlarmClock* AlarmNode::getbeckendAlarmClock()
{
		return backendAlarmClock;
}

void AlarmNode::setbackendAlarmClock(AlarmClock* clockObj)
{
	
	std::cout << clockObj->to_json(*clockObj) << "\n";
		backendAlarmClock = clockObj;
		std::cout << backendAlarmClock->to_json(*backendAlarmClock) << "\n";
}
