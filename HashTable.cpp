#include "HashTable.hpp"


HashTable::HashTable(){
	
	table = new Node*[total];
	
	for(int i=0; i<total;i++){
		table[i] = nullptr;
	}

	size = 0;
	hash = 0;
}

int HashTable::Hash(std::string key){	

	for(int i=0; i< key.length();i++){
		
		hash = 0;
		
		if(key[i] % 2 !=0){
			hash += key[i];
		}
		else{
			hash -= key[i];
		}


	}
	
	while(hash < 0){
        	hash += 10;
	}
 
	while(hash > total){
        	hash -= 10;
	}
	
	return hash % total;

}

void HashTable::Add(std::string key, std::string password){
	
	if(size >= total){
		return;
	}
	hash = Hash(key);
	
	if(table[hash] == nullptr){
		table[hash] = new Node(key, password);
		table[hash]->SetNext(nullptr);
	}else{
		Node* temp = table[hash];
		table[hash] = new Node(key, password);
		table[hash]->SetNext(temp);
		delete temp;	
	}
		
	size++;

}

/*bool HashTable::Find(std::string key){
	
	hash = Hash(key);
	
	if(table[hash] == nullptr){
		std::cout << "false";
		return false;
	}
	else if(table[hash]->GetKey() == key){
		std::cout << "found";
		return true;	
	}else{
		Node* temp = table[hash];

		while(temp != nullptr){
			temp = temp->GetNext();
			
			if(temp->GetKey() == key){
				std::cout<< "found";
			}

		}
		delete temp;
	}
	std::cout << "false";
	return false;
}*/

HashTable::~HashTable(){
	for(int i=0; i<size; i++){
		delete table[i];
	}
	delete[] table;
}












