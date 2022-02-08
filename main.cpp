// Elena Lucci COP4534
#include <iostream>
#include "PassManager.hpp"

int main(){
	
	PassManager password;	
	password.ReadFile();	
	//password.FindTester("SMITH");	
	password.Print();
	return 0;
}
