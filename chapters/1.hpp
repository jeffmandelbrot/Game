#include "../includes.hpp"
#include "../functions.hpp"

using std::string;
using std::vector;
/*
void draw_title_screen_bg(){
	
}
*/
exitcode chapter_1(){
/*	std::cout << "Math::sqrt testing\n" << std::flush;

	Math math(100);
	for (unsigned i = 0; i < 100; i++)
		std::cout << math.n_root(i) << ", " << std::flush;
*/
	Math math;
	vector <double> vals{1,2,3,4,5,6,67,84,44,30,22,100};
	math.print_vec(vals);
	math.map(vals);
	math.print_vec(vals);

	return success;
}
