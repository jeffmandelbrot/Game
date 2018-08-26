#ifndef MATH_HPP
#define MATH_HPP

#include "includes.hpp"

using std::string;
using std::vector;

struct Math{
	Math(){std::cout.precision(15);}

	double long sqrt(const double long, const unsigned long long=15000, const double long=1.005);
	unsigned long long sqrt_results_size(const double long, const unsigned long long=15000, const double long=1.005);

	template <typename T>	
	T get_middle_elem(const vector <T>);
	template <typename T>
	bool close(const T, const T, const double long=1.05);
	template <typename T>
	bool in_range(const T, const T, const T);
};

#endif // MATH_HPP
