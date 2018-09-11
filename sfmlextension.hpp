#ifndef SFMLEXTENSION_HPP
#define SFMLEXTENSION_HPP

#include "includes.hpp"

class SFMLExtension{
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

	bool text_clicked(const sf::RenderWindow &window, const sf::Text text){
		const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		return text.getGlobalBounds().contains(mousePos.x, mousePos.y) && m1_pressed();
	}
};

#endif // SFMLEXTENSION_HPP
