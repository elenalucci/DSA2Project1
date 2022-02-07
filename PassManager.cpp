#include "PassManager.hpp"


void PassManager::ReadFile(){
	
	inFile.open("lastNames.txt");
	outFile.open("raw.txt");
	outFile2.open("encrypted.txt");
	std::string trash;

	for(int i=0;i<5; i++){
		inFile >> lastName >> trash >> trash >> trash;
		password = GeneratePass(lastName);
		outFile << lastName << " " << password << std::endl;
		firstFiveLast[i] = lastName;
		firstFivePass[i] = password;
		encryptedPass = cipher.Encrypt(password);
		hash.Add(lastName, encryptedPass);
		outFile2 << lastName << " " << encryptedPass << std::endl;

	}

	while(!inFile.eof()){
		
		inFile >> lastName >> trash >> trash >> trash;	
		password = GeneratePass(lastName);
		outFile << lastName << " " << password << std::endl;
		encryptedPass = cipher.Encrypt(password);
		hash.Add(lastName, encryptedPass);
		outFile2 << lastName << " " << encryptedPass << std::endl;
	
	}
	
	inFile.close();
	outFile.close();
	outFile2.close();	
		
}

PassManager::PassManager(){
	lastName = "";
	password = "";
	encryptedPass = "";
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

/*void PassManager::FindTester(std::string lastName){

	hash.Find(lastName);
}*/

bool PassManager::PassTester(std::string password1,std::string password2){
	if(password1 == password2){
		return true;
	} 

	return false;

}

std::string PassManager::WrongPass(std::string password){
	
	return password += "x";
	
}

void PassManager::Print(){
	std::cout << "Legal:"<< std::endl;
	std::cout << "Userid" << std::setw(20) << "Password" << std::setw(20)<< "Attempted" << std::setw(20) << "Result" << std::endl;
	for(int i = 0; i< 5; i++){
		std::cout << firstFiveLast[i] << std::setw(20) << firstFivePass[i] << std::setw(20) << firstFivePass[i] << std::setw(20);
		if(PassTester(firstFivePass[i],firstFivePass[i]) == false){
			std::cout << "no match" << std::endl;
		}
		else{
			std::cout << "match" << std::endl;
		}	
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Illegal:"<< std::endl;
        std::cout << "Userid" << std::setw(20) << "Password" << std::setw(20)<< "Attempted" << std::setw(20) << "Result" << std::endl;
	
	std::string wrongPassList[5];
	for(int i=0; i<5; i++){
		wrongPassList[i] = WrongPass(firstFivePass[i]);
	}        

	for(int i = 0; i< 5; i++){
        	std::cout << firstFiveLast[i] << std::setw(20) << firstFivePass[i] << std::setw(20) << wrongPassList[i] << std::setw(20);
                if(PassTester(firstFivePass[i], wrongPassList[i]) == false){
                	std::cout << "no match" << std::endl;
                }
                else{
                        std::cout << "match" << std::endl;
                }
        }
}
