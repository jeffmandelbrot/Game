#include "../includes.hpp"
#include "../functions.hpp"

using std::string;
using std::vector;
/*
void draw_title_screen_bg(){
	
}
*/
exitcode chapter_1(){
	std::cout << "Math::sqrt testing\n" << std::flush;

	Math math(100);
	for (unsigned i = 0; i < 100; i++)
		std::cout << math.n_root(i) << ", " << std::flush;

	return success;
}
