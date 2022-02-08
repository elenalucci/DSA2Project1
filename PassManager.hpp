// Elena Lucci COP4534
#ifndef PassManager_hpp
#define PassManager_hpp
#include "Cipher.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

class PassManager{
	private:
	    std::ifstream inFile;
	    std::ofstream outFile;
	    std::ofstream outFile2;
	    std::string lastName; 
	    std::string password;
	    std::string encryptedPass;
	    std::string firstFiveLast[5];
	    std::string firstFivePass[5];		
	    Cipher cipher;
	    HashTable hash; 
	
	public:
	    PassManager();
	    void ReadFile();
	    std::string GeneratePass(std::string lastName);
	    void FindTester(std::string lastName);
	    bool PassTester(std::string password1,std::string password2);
	    void Print();
	    std::string WrongPass(std::string password);
};
#endif

