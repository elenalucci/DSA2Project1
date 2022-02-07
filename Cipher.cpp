#include "Cipher.hpp"

Cipher::Cipher(){
	password = "";
	encryptedPass = "";
}

std::string Cipher::Encrypt(std::string password){
	
	encryptedPass = "";
	
	for(int i=0; i<password.size(); i++){
		encryptedPass += (char) (((int)password[i]- 'A' + (int)key[i]- 'A') % 26) + 'A';
	}

	return encryptedPass;
}

