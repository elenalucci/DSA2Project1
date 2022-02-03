#ifndef PassManager_hpp
#define PassManager_hpp
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
	    std::string lastName; 
	    std::string password;		

	public:
	    PassManager();
	    void ReadFile();
	    std::string GeneratePass(std::string lastName);
};
#endif

