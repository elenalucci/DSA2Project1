#include "PassManager.hpp"


void PassManager::ReadFile(){
	inFile.open("lastNames.txt");
	outFile.open("raw.txt");
	std::string trash;

	while(!inFile.eof()){
		
		inFile >> lastName >> trash >> trash >> trash;	
		password = GeneratePass(lastName);
		outFile << lastName << " " << password << std::endl;
		
	}
	
	inFile.close();
	outFile.close();

	
}

PassManager::PassManager(){
	lastName = "";
	password = "";
}

std::string PassManager::GeneratePass(std::string lastName){
	
	char letter;
	int num;	
	
	num = lastName[0] + 32;
	
	if(num > lastName[1]){
		num = num - lastName[1];
	}
	else if(num < lastName[1]){
		num = lastName[1] - num;
	}

	std::stringstream ss;
	srand(time(NULL));	
	for(int i=0; i<9; i++){
		
		letter = 'a'  + rand()% 26 + num;	
		while(letter >122){
			letter = letter - rand()% 10 +1;
		}
		
		while(letter < 97){
			letter = letter + rand()% 10 +1;
		}
		
		ss << letter;
	}
	ss >> password;	
	return password;
}


