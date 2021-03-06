#ifndef CHAPTER_2_HPP
#define CHAPTER_2_HPP

#include "../includes.hpp"
#include "../functions.hpp"

extern unsigned numRecOpen;
extern unsigned chapterNum;

exitcode chapter_2(){
	system("sleep 1"); // Wait for recording prevention
	std::cout << "The number of recording programs opened is: " << numRecOpen << "!\n";
	return success;
}

#endif // CHAPTER_2_HPP
