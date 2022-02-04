#ifndef PassManager_hpp
#define PassManager_hpp
#include "Cipher.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

class PassManager{
	private:
	    std::ifstream inFile;
	    std::ofstream outFile;
	    std::ofstream outFile2;
	    std::string lastName; 
	    std::string password;
	    std::string encryptedPass;		
	    Cipher cipher;    
	
	public:
	    PassManager();
	    void ReadFile();
	    std::string GeneratePass(std::string lastName);
};
#endif

