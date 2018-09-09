// Copyright Kiva 2018
// https://github.com/kivattt/game

#include "includes.hpp"
#include "functions.hpp"

using std::string;

// Global vars
unsigned numRecOpen;
unsigned chapterNum;

const unsigned width=1600,height=900;
sf::RenderWindow window(sf::VideoMode(width, height), "game", sf::Style::Titlebar | sf::Style::Close);

int main(){
	std::thread preventRecording(recording_prevention);


	exitcode code = temp;
	for (chapterNum = 1; code != finished; chapterNum++){
		code = run_chapter(chapterNum);

		if (code == error)
			return error;
	}

	std::cin.get(); // Debugging

	return success;
}
