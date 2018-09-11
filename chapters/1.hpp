#ifndef CHAPTERS_1_HPP
#define CHAPTERS_1_HPP

#include "../includes.hpp"
#include "../functions.hpp"

using std::string;
using std::vector;

extern sf::RenderWindow window;
extern const sf::Time defaultTextDelay;
extern const unsigned defaultVerticalTextSpacing;
extern const unsigned defaultHorizontalTextSpacing;

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
		color.g = (window.getSize().y/2 - r*1.8) < 0 ? 0 : window.getSize().y/2 - r*1.8;

		unsigned numPoints = r*4.45;

		draw_circle(window, spr, window.getSize().x/2, window.getSize().y/2, r, numPoints, color);
		window.display();
	}
}

void draw_text_gradually(sf::RenderWindow &window, sf::Text &text, const sf::Time delay){
	const string textStr = text.getString();

	for (unsigned i = 1; i <= textStr.length(); i++){
		text.setString(textStr.substr(0,i));
		window.draw(text);
		window.display();
		sf::sleep(delay);
	}
}

exitcode chapter_1(){
	std::cout << "SFML version: " << SFML_VERSION_MAJOR << '.' << SFML_VERSION_MINOR << '\n';
	// Play background music
	sf::Music bgMusic;
	bgMusic.openFromFile("audio/lsd.wav");
//	bgMusic.play();

	// Font
	sf::Font monospace;
	monospace.loadFromFile("monospace.otf");

	// bangbang.mov text
	sf::Text bangbangTxt;
	bangbangTxt.setFont(monospace);
	bangbangTxt.setString("welcome");
	bangbangTxt.setCharacterSize(68);
	bangbangTxt.setPosition(window.getSize().x/2 - bangbangTxt.getLocalBounds().width/2, window.getSize().y/2.5);

	sf::Texture pxlTxt; pxlTxt.loadFromFile("imgs/pixel.png");
	sf::Sprite  pxlSpr; pxlSpr.setTexture(pxlTxt);

	bool closed = false;

	// Draw intro bg
//	draw_intro_bg(window, pxlSpr);

	draw_text_gradually(window, bangbangTxt, defaultTextDelay);

	// Main menu text
	sf::Text startText;
	startText.setFont(monospace);
	startText.setString("start");
	startText.setCharacterSize(40);

	sf::Text exitText;
	exitText.setFont(monospace);
	exitText.setString("exit");
	exitText.setCharacterSize(40);

	startText.setFillColor({0, 0, 0});
	exitText. setFillColor({0, 0, 0});

	const unsigned startTextX = window.getSize().x/2 - startText.getLocalBounds().width/2;
	const unsigned startTextY = window.getSize().y/2 + window.getSize().y/16;
	const unsigned exitTextX  = window.getSize().x/2 - exitText.getLocalBounds().width/2;
	const unsigned exitTextY  = window.getSize().y/2 + window.getSize().y/16 +startText.getLocalBounds().height + defaultVerticalTextSpacing;

	startText.setPosition(startTextX, startTextY);
	exitText.setPosition(exitTextX, exitTextY);

	draw_text_gradually(window, startText, defaultTextDelay);
	draw_text_gradually(window, exitText, defaultTextDelay);

	SFMLExtension extension;
	while (!closed){
		// Backup for debugging
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			closed = true;

		closed = extension.text_clicked(window, exitText);
	}

	return success;
}

#endif // CHAPTERS_1_HPP
