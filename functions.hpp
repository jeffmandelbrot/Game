#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "includes.hpp"
#include "chapters.hpp"

using std::string;
using std::vector;

const vector <string> recordingPrograms{
	"obs", // Screen recording programs
	"obs-studio",	
	"kazam",
	"vokoscreen",
	"simplescreenrecorder",
	"recordmydesktop",
	"gtk-recordmydesktop",
	"ffmpeg",
	"green-recorder",
	"peek",
	"gifine",
	"byzanz",
	"wink",
	"freezer",
	"krut",
	"audacity", // Mic/Sound recording programs
	"audio-recorder",
	"sox",
	"ardour",
	"arecord",
	"qarecord",
	"avconv",
	"vlc",
	"fmedia",
	"gnome-sound-recorder",
	"ecasound",
	"frinika",
	"ocenaudio",
	"mixbus",
	"discord",
	"scrot", // Screenshot programs
	"shutter",
	"gnome-screenshot",
	"Discord", // Other (screenshare)
	"skype"
};

bool program_open(const string process){
	return system(("pgrep -x " + process + " > /dev/null").c_str()) == 0;
}

bool kill_process(const string process){
	return system(("pkill " + process).c_str()) == 0;
}

// Always tries to kill any recording programs
extern unsigned numRecOpen;
void recording_prevention(){
	for (;;){
		for (std::string recorder : recordingPrograms)
			numRecOpen += kill_process(recorder);
	}
}

exitcode run_chapter(const unsigned n){
	switch (n){
		case 1: return chapter_1(); break;
		case 2: return chapter_2(); break;
	}

	std::cout << "---Finished, press enter to exit---\n";
	return finished;
}

#endif // FUNCTIONS_HPP
