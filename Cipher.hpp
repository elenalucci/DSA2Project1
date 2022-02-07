#ifndef Cipher_hpp
#define Cipher_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Cipher{
	
	private:
	    std::string password;
	    std::string encryptedPass;
	    std::string decryptedPass;
	    std::string const key = "hijackers";
	public:
	    Cipher();
	    std::string Encrypt(std::string password);

};

#endif

