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

	Math meth;

	const vector <unsigned> vals{1,2,3,4,5,6,7,8,9,10};
	for (auto i : vals)
		std::cout << "my_sqrt(" << i << ", 1000, 1.01) = " << meth.sqrt(i, 1000, 1.01) << '\n';

	return success;
}
