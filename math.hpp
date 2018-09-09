#ifndef MATH_HPP
#define MATH_HPP

// Constants
#define TAU 6.2831853071795864769
#define PI  3.1415926535897932384
#define E   2.7182818284590452353
#define PHI 1.6180339887498948482

#include "includes.hpp"

using std::string;
using std::vector;

struct Math{
	Math(const unsigned short numberPrecision=8){std::cout.precision(numberPrecision);}

	// Function definitions (in hpp file because of weird template errors)
	template <typename T>
	bool in_range(const T val, const T low, const T high){
		return val >= low && val <= high;
	}

	double long pow(const double long n, const unsigned long long power=2){
		double long out = n;
		for (unsigned i = 1; i < power; i++)
			out *= n;
		return out;
	}

	// Default power in n_root* is 2 (square)
	double long n_root(const double long n, const unsigned long long iterPrecision=55000, const double long closePrecision=1.001, const unsigned long long power=2){
		if (n == 0) return 0;
		
		vector <double> validResults;
		
		for (double long i = n/iterPrecision; i < n; i += n/iterPrecision){
			if (in_range(pow(i, power), n/closePrecision, n*closePrecision))
				validResults.push_back(i);
		}
		
		return validResults[validResults.size()/2];
	}

	unsigned long long n_root_result_size(const double long n, const unsigned long long iterPrecision=55000, const double long closePrecision=1.001, const unsigned long long power=2){
		unsigned long long out = 0;
		for (double long i = 0; i < n; i += n/iterPrecision)
			out += in_range(pow(i, power), n/closePrecision, n*closePrecision);
		
		return out;
	}

	template <typename T>
	void map(const vector <T> &vec, const T high=1){
		const T highestVecVal = get_highest_val(vec);
		for (unsigned long long i = 0; i < vec.size(); i++){
			vec[i] /= highestVecVal;
			vec[i] *= high;
		}
	}

	template <typename T>
	vector <T> map_copy(const vector <T> vec, const T high=1){
		vector <T> tmp = vec;
		map(tmp, high);
		return tmp;
	}


	template <typename T>
	void print_vec(const vector <T> vec){
		if (vec.empty()) return;

		if (vec.size() == 1){
			std::cout << '{' << vec[0] << '}';
			return;
		}

		std::cout << '{' << vec[0];
		for (unsigned i = 1; i < vec.size(); i++)
			std::cout << ',' << vec[i];
		std::cout << '}';
	}

	template <typename T>
	vector <T> polar_to_cartesian(const T deg, const T r){
		return {cos(deg) * r, sin(deg) * r};
	}
};

#endif // MATH_HPP
