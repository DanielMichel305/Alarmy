#pragma once
#include <TGUI/TGUI.hpp>



class ToggleSwitch : public tgui::Panel
{
private:

	sf::Color backgroundColorEnabled = sf::Color(33, 0, 93);         ///Some shade of dark purpule
	sf::Color backgroundColorDisabled = sf::Color(230, 230, 250);  ///Lavendar
	sf::Color toggleColorEnabled = sf::Color(230, 230, 250);
	sf::Color toggleColorDisabled = sf::Color(112, 128, 144);

	tgui::RadioButton::Ptr toggle;
	bool switchSet = true;


public:

	ToggleSwitch();
	void setToggled(bool settoggled);
	bool isToggled();




	void setBackgroundColorEnabled(const sf::Color& color);
	void setBackgroundColorDisabled(const sf::Color& color);
	void setToggleColorEnabled(const sf::Color& color);
	void setToggleColorDisabled(const sf::Color& color);
	const sf::Color& getBackgroundColorEnabled() const;
	const sf::Color& getBackgroundColorDisabled() const;
	const sf::Color& getToggleColorEnabled() const;
	const sf::Color& getToggleColorDisabled() const;




};