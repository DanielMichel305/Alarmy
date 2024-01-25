#include "ToggleSwitch.h"

ToggleSwitch::ToggleSwitch()
{
	setSize(30, 15);
	getRenderer()->setRoundedBorderRadius(999);
	getRenderer()->setBackgroundColor(backgroundColorEnabled);


	toggle = tgui::RadioButton::create();
	toggle->setChecked(true);
	toggle->setSize(getSize().x / 2.5, getSize().y);
	toggle->setPosition(getSize().x - ((getSize().x / 2.5) * 1.17), getSize().y * 0.14);
	toggle->getRenderer()->setCheckColor(toggle->getRenderer()->getBackgroundColor());
	toggle->getRenderer()->setCheckColorHover(toggle->getRenderer()->getBackgroundColor());


	toggle->onClick([&]() {

		if (!toggle->isChecked() || !switchSet) {

			switchSet = true;
			toggle->setPosition(getSize().x - 25, getSize().y * 0.14);
			toggle->setPosition(getSize().x - ((getSize().x / 2.5) * 1.17), getSize().y * 0.14);
			toggle->getRenderer()->setBackgroundColor(getToggleColorEnabled());
			toggle->getRenderer()->setBackgroundColorHover(getToggleColorEnabled());
			toggle->getRenderer()->setCheckColor(getToggleColorEnabled());
			toggle->getRenderer()->setCheckColorHover(getToggleColorEnabled());
			getRenderer()->setBackgroundColor(getBackgroundColorEnabled());

		}
		else if (toggle->isChecked() || switchSet) {

			switchSet = false;
			toggle->setChecked(false);
			toggle->setPosition(2, getSize().y * 0.14);
			toggle->setPosition(2, getSize().y * 0.14);
			toggle->getRenderer()->setBackgroundColor(getToggleColorDisabled());
			toggle->getRenderer()->setBackgroundColorHover(getToggleColorDisabled());
			toggle->getRenderer()->setCheckColor(getToggleColorDisabled());
			toggle->getRenderer()->setCheckColorHover(getToggleColorDisabled());
			getRenderer()->setBackgroundColor(getBackgroundColorDisabled());
		}

		});

	add(toggle);
}

void ToggleSwitch::setToggled(bool settoggled)
{
	if (settoggled) {
		switchSet = true;
		toggle->setPosition(getSize().x - 25, getSize().y * 0.14);
		toggle->getRenderer()->setBackgroundColor(getToggleColorEnabled());
		toggle->getRenderer()->setBackgroundColorHover(getToggleColorEnabled());
		toggle->getRenderer()->setCheckColor(getToggleColorEnabled());
		toggle->getRenderer()->setCheckColorHover(getToggleColorEnabled());
		getRenderer()->setBackgroundColor(getBackgroundColorEnabled());
	}
	else {
		switchSet = false;
		toggle->setChecked(false);
		toggle->setPosition(2, getSize().y * 0.14);
		toggle->getRenderer()->setBackgroundColor(getToggleColorDisabled());
		toggle->getRenderer()->setBackgroundColorHover(getToggleColorDisabled());
		toggle->getRenderer()->setCheckColor(getToggleColorDisabled());
		toggle->getRenderer()->setCheckColorHover(getToggleColorDisabled());
		getRenderer()->setBackgroundColor(getBackgroundColorDisabled());
	}

}

bool ToggleSwitch::isToggled()
{
	return switchSet;
}



void ToggleSwitch::setBackgroundColorEnabled(const sf::Color& color) {
	backgroundColorEnabled = color;

}

void ToggleSwitch::setBackgroundColorDisabled(const sf::Color& color) {
	backgroundColorDisabled = color;

}

void ToggleSwitch::setToggleColorEnabled(const sf::Color& color) {
	toggleColorEnabled = color;

}

void ToggleSwitch::setToggleColorDisabled(const sf::Color& color) {
	toggleColorDisabled = color;
}

// Getters
const sf::Color& ToggleSwitch::getBackgroundColorEnabled() const {
	return backgroundColorEnabled;
}

const sf::Color& ToggleSwitch::getBackgroundColorDisabled() const {
	return backgroundColorDisabled;
}

const sf::Color& ToggleSwitch::getToggleColorEnabled() const {
	return toggleColorEnabled;
}

const sf::Color& ToggleSwitch::getToggleColorDisabled() const {
	return toggleColorDisabled;
}


