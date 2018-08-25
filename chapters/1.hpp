#include "../includes.hpp"
#include "../functions.hpp"

using std::string;
using std::vector;

extern unsigned chapterNum;

template <typename T>
bool in_range(const T val, const T low, const T high){
	return val >= low && val <= high;
}

template <typename T>
bool close(const T val1, const T val2, const double precision=1.15){
	return in_range(val1, val2/precision, val2*precision);
}

unsigned my_ceil(const double n){
	return n+1;
}

template <typename T>
T get_middle_elem(const vector <T> vec){
	if (vec.empty()) return {};
	const unsigned middleIdx = my_ceil(vec.size() / 2);
	return vec[middleIdx];
}

template <typename T>
void print_vec(const vector <T> vec){
	if (vec.empty()) return;
	std::cout << "{" << vec[0] << ",";
	for (unsigned i = 1; i < vec.size(); i++)
		std::cout << ", " << vec[i];
}

double my_sqrt(const double n, const unsigned iterPrecision=100, const double closePrecision=1.15){
	vector <double> validResults;

	for (double i = 0; i < n; i += n/iterPrecision){
		if (close(i*i, n, closePrecision))
			validResults.push_back(i);
	}

	// Debugging
	print_vec(validResults);
	return get_middle_elem(validResults);

	return 0;
}
/*
void draw_title_screen_bg(){
	
}
*/
exitcode chapter_1(){
	std::cout << "my_sqrt testing\n";

	const vector <unsigned> vals{1,2,3,4,5,6,7,8,9,10};
	for (auto i : vals)
		std::cout << "my_sqrt(" << i << ", 1000, 1.05) = " << my_sqrt(i, 1000, 1.05) << '\n';

	return success;
}
