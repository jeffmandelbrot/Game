#ifndef FILEAUTHCHECK_HPP
#define FILEAUTHCHECK_HPP

#include "includes.hpp"

using std::string;
using std::vector;

// For checking if file is original without having to include entire file contents in source
class FileAuthenticator{
	const string filesPath = "bin/";
	const string audioPath = filesPath + "audio/";
	
	// List of numbers to "authenticate" every file
	// First number is size in bytes of file
	// Second is the sum of every char in file
	map <string, unsigned long long, unsigned long long> fNums{};
	
	map <string, unsigned long long, unsigned long long> audioFNums{{"bg.wav", REPLACETHISNUM, REPLACETHISNUMTOO},
												{"illegal.wav", REPLACETHISNUM, REPLACETHISNUMTOO},
												{"lsd.wav", REPLACETHISNUM, REPLACETHISNUMTOO},
												{"panic!_at_the_mall.wav", REPLACETHISNUM, REPLACETHISNUMTOO},
												{"un_subtle.wav", REPLACETHISNUM, REPLACETHISNUMTOO},
												{"vague.wav", REPLACETHISNUM, REPLACETHISNUMTOO}};
	for (auto &idx : audioFSizes)
		idx.first = audioPath + idx.first; // Add audio path to every audio file
	
	public:
	unsigned long long get_size(const string filename){
		std::ifstream file(filename.c_str(), std::ifstream::in, std::ifstream::binary);
		if (!file.is_open()) return error;
		
		file.seekg(0, std::ios::end);
		unsigned long long fSize = file.tellg();
		file.close();
		
		return fSize;
	}



	bool authentic(const string filename){
		if ()
	}
};

#endif // FILEAUTHCHECK_HPP
