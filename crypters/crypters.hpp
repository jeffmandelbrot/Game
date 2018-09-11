// I will revamp this file later, such as making it use an alphabet

#ifndef CRYPTERS_HPP
#define CRYPTERS_HPP

#include "../includes.hpp"

using std::string;

class Crypt{
	unsigned char key = 255; // Default key

	public:
	void set_key(const unsigned char newKey){
		key = newKey;
	}

	unsigned char get_key(){
		return key;
	}

	/*
	 * Encryption functions
	*/
	string xorEnc(const string);
	string xorEnc(const string, const unsigned char);

	string rotEnc(const string);
	string rotEnc(const string, const unsigned char);
};

#endif // CRYPTERS_HPP
