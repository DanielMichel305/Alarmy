#pragma once
#include <TGUI/TGUI.hpp>

#include "AlarmClock.h"
#include "ToggleSwitch.h"

class AlarmNode : public tgui::Panel
{
private:
	std::shared_ptr<ToggleSwitch> alarmActivate;
	tgui::Label::Ptr alarmActivateLabel;
	tgui::Label::Ptr clockLabel;	
	tgui::TextArea::Ptr clockDescriptionLabel;
	tgui::CheckBox::Ptr dayCheckBox[7];

	AlarmClock* backendAlarmClock = new AlarmClock();

public:
	AlarmNode();
	AlarmNode(AlarmClock clockObj);
	void setPosition(float x, float y);

	////Alarm Node Related Functions

	bool isAlarmActivated();
	void UIAlarmActivate(bool status);

	AlarmClock* getbeckendAlarmClock();
	void setbackendAlarmClock(AlarmClock* clockObj);

};

