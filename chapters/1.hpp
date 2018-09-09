#ifndef CHAPTERS_1_HPP
#define CHAPTERS_1_HPP

#include "../includes.hpp"
#include "../functions.hpp"

using std::string;
using std::vector;

extern sf::RenderWindow window;

void draw_spr(sf::RenderWindow &window, sf::Sprite &spr, const unsigned x, const unsigned y, const sf::Color color={255,255,255}){
	spr.setPosition(x, y);
	spr.setColor(color);
	window.draw(spr);
}

void draw_circle(sf::RenderWindow &window, sf::Sprite &spr, const unsigned x, const unsigned y, const unsigned r, const unsigned numPoints=800, const sf::Color color={255,255,255}){
	for (double deg = 0; deg < TAU; deg += TAU/numPoints){
		unsigned newX = cos(deg) * r + x;
		unsigned newY = sin(deg) * r + y;

		draw_spr(window, spr, newX, newY, color);
	}
}



void draw_intro_bg(sf::RenderWindow &window, sf::Sprite &spr){
	for (double r = 5; r < window.getSize().y/2; r *= 1.000021){
		sf::Color color;
		color.r = (window.getSize().y/2 - r*3) < 0 ? 0 : window.getSize().y/2 - r*3;
		color.b = pow(r, PI);
		color.g = (window.getSize().y/2 - r*2) < 0 ? 0 : window.getSize().y/2 - r*2;

		unsigned numPoints = r*4.45;

		draw_circle(window, spr, window.getSize().x/2, window.getSize().y/2, r, numPoints, color);
		window.display();
	}
}

exitcode chapter_1(){
	// Play background music
	sf::Music bgMusic;
	bgMusic.openFromFile("audio/lsd.wav");
	bgMusic.play();

	// Font
	sf::Font monospace;
	monospace.loadFromFile("monospace.otf");

	// bangbang.mov text
	sf::Text bangbangTxt;
	bangbangTxt.setFont(monospace);
	bangbangTxt.setString("welcome");
	bangbangTxt.setCharacterSize(14);
	bangbangTxt.setPosition(window.getSize().x/2, window.getSize().y/2);

	sf::Texture pxlTxt; pxlTxt.loadFromFile("imgs/pixel.png");
	sf::Sprite  pxlSpr; pxlSpr.setTexture(pxlTxt);

	bool closed = false;

	draw_intro_bg(window, pxlSpr);

	while (!closed){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			closed = true;

		window.draw(bangbangTxt);
		window.display();
	}

	return success;
}

#endif // CHAPTERS_1_HPP
