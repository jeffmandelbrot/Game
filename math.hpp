#ifndef MATH_HPP
#define MATH_HPP

#include "includes.hpp"

using std::string;
using std::vector;

struct Math{
	Math(const unsigned short numberPrecision=8){std::cout.precision(numberPrecision);}

	// Default power in n_root* is 2 (square)
	double long n_root(const double long, const unsigned long long=55000, const double long=1.001, const unsigned long long power=2);
	unsigned long long n_root_result_size(const double long, const unsigned long long=55000, const double long=1.001, const unsigned long long=2);
	double long pow(const double long, const unsigned long long=2);
	template <typename T>
	vector <T> map_copy(const vector <T>, const unsigned long long=1);
	template <typename T>
	void map(const vector <T> &, const unsigned long long=1);

	template <typename T>	
	T get_middle_elem(const vector <T>);
	template <typename T>
	bool in_range(const T, const T, const T);
	template <typename T>
	void print_vec(const vector <T>);
	template <typename T>
	T Math::get_val(const vector <T>, const bool=true);
};

#endif // MATH_HPP
