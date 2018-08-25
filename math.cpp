#include "math.hpp"
#include "includes.hpp"

using std::string;
using std::vector;

template <typename T>
bool Math::in_range(const T val, const T low, const T high){
	return val >= low && val <= high;
}

template <typename T>
bool Math::close(const T val1, const T val2, const double precision){
	return in_range(val1, val2/precision, val2*precision);
}

template <typename T>
T Math::get_middle_elem(const vector <T> vec){
	if (vec.empty()) return {};
	return vec[vec.size()/2];
	// Compiler complains about this:
	//return vec.empty() ? {} : vec[vec.size()/2];
}

double Math::sqrt(const double n, const unsigned iterPrecision, const double closePrecision){
	vector <double> validResults;

	for (double i = 0; i < n; i += n/iterPrecision){
		if (close(i*i, n, closePrecision))
			validResults.push_back(i);
	}

	return get_middle_elem(validResults);

	return 0;
}
