#ifndef MOUSEPRESS_HPP
#define MOUSEPRESS_HPP

#include "includes.hpp"

class MousePressChecker{
	bool holdingM1 = false;
	bool holdingM2 = false;

	public:

	bool m1_pressed(){
		const bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		const bool out = (!holdingM1) && pressed;
		holdingM1 = pressed;
		return out;
	}

	bool m2_pressed(){
		const bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
		const bool out = (!holdingM2) && pressed;
		holdingM2 = pressed;
		return out;
	}
};

#endif
