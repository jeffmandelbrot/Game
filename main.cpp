#include "includes.hpp"
#include "functions.hpp"

using std::string;

// Global vars
unsigned numRecOpen;
unsigned chapterNum;

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
