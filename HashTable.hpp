// Elena Lucci COP4534
#ifndef HashTable_hpp
#define HashTable_hpp
#include "Node.hpp"
#include <string>
#include <iostream>

class HashTable{

	private:
	    const int total = 89003;
	    int size;
	    int hash;
	    Node** table;
	    
	public:
	    HashTable();
	    ~HashTable();
	    int Hash(std::string key);
	    void Add(std::string key, std::string password);
	    //bool Find(std::string key);
	    
};


#endif
