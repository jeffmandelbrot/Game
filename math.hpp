#ifndef MATH_HPP
#define MATH_HPP

#include "includes.hpp"

using std::string;
using std::vector;

struct Math{
	Math(const unsigned short numberPrecision=8){std::cout.precision(numberPrecision);}

	double long n_root(const double long, const unsigned long long=15000, const double long=1.005, const unsigned long long power=2);
	unsigned long long n_root_result_size(const double long, const unsigned long long=15000, const double long=1.005, const unsigned long long=2);
	double long pow(const double long, const unsigned long long=2);

	template <typename T>	
	T get_middle_elem(const vector <T>);
	template <typename T>
	bool close(const T, const T, const double long=1.05);
	template <typename T>
	bool in_range(const T, const T, const T);
};

#endif // MATH_HPP
