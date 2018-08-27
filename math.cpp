#include "math.hpp"
#include "includes.hpp"

using std::string;
using std::vector;

template <typename T>
bool Math::in_range(const T val, const T low, const T high){
	return val >= low && val <= high;
}

double long Math::pow(const double long n, const unsigned long long power){
	double long out = n;
	for (unsigned i = 1; i < power; i++)
		out *= n;
	return out;
}

double long Math::n_root(const double long n, const unsigned long long iterPrecision, const double long closePrecision, const unsigned long long power){
	if (n == 0) return 0;

	vector <double> validResults;

	for (double long i = n/iterPrecision; i < n; i += n/iterPrecision){
		if (in_range(pow(i, power), n/closePrecision, n*closePrecision))
			validResults.push_back(i);
	}

	return validResults[validResults.size()/2];
}

unsigned long long Math::n_root_result_size(const double long n, const unsigned long long iterPrecision, const double long closePrecision, const unsigned long long power){
	unsigned long long out = 0;
	for (double long i = 0; i < n; i += n/iterPrecision)
		out += in_range(pow(i, power), n/closePrecision, n*closePrecision);

	return out;
}

template <typename T>
void Math::map(const vector <T> &vec, const unsigned long long highestVal){
	const vector <T> tmp = map_copy(vec, highestVal);
	return tmp;
}

template <typename T>
vector <T> Math::map_copy(const vector <T> vec, const unsigned long long highestVal){
	const vector <T> tmp = map()
}
