// Elena Lucci COP4534
#include "Cipher.hpp"
//default constructor
Cipher::Cipher(){
	password = "";
	encryptedPass = "";
}
// encrypts password
std::string Cipher::Encrypt(std::string password){
	
	encryptedPass = "";
	
	for(int i=0; i<password.size(); i++){
		encryptedPass += (char) (((int)password[i]- 'A' + (int)key[i]- 'A') % 26) + 'A';
	}

	return encryptedPass;
}

