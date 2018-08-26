#include "../includes.hpp"
#include "../functions.hpp"

using std::string;
using std::vector;

/*
void draw_title_screen_bg(){
	
}
*/
exitcode chapter_1(){
	std::cout << "Math::sqrt testing\n";

	Math math;

	std::cout << "math.sqrt(2) = " << math.sqrt(2) << '\n';

	return success;
}
