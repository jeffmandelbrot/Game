#include "crypters.hpp"

using std::string;

// Xor "encryption"
string Crypt::xorEnc(const string str){
	return Crypt::xorEnc(str, key);
}

string Crypt::xorEnc(const string str, const unsigned char localKey){
	string out;
	for (char chr : str)
		out += chr ^ localKey;
	return out;
}

// ROT "encryption"
string Crypt::rotEnc(const string str){
	return Crypt::rotEnc(str, key);
}

string Crypt::rotEnc(const string str, const unsigned char localKey){
	string out;
	for (char chr : str)
		out += (chr + localKey) % 256;
	return out;
}
