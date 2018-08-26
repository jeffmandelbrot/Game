#include "math.hpp"
#include "includes.hpp"

using std::string;
using std::vector;

template <typename T>
bool Math::in_range(const T val, const T low, const T high){
	return val >= low && val <= high;
}

template <typename T>
bool Math::close(const T val1, const T val2, const double long precision){
	return in_range(val1, val2/precision, val2*precision);
}

double long Math::sqrt(const double long n, const unsigned long long iterPrecision, const double long closePrecision){
	if (n == 0) return 0;

	vector <double> validResults;

	for (double long i = n/iterPrecision; i < n; i += n/iterPrecision){
		if (close(i*i, n, closePrecision))
			validResults.push_back(i);
	}

	return validResults[validResults.size()/2];
}

unsigned long long Math::sqrt_results_size(const double long n, const unsigned long long iterPrecision, const double long closePrecision){
	unsigned long long out = 0;
	for (double long i = 0; i < n; i += n/iterPrecision)
		out += close(i*i, n, closePrecision);

	return out;
}
