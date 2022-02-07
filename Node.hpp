#ifndef NODE_HPP
#define NODE_HPP
#include <string>

class Node{
	
	private:
	    std::string key;
	    std::string password;
	    Node* next;
	    
	public:
	    Node(std::string key,std::string password);
	    void SetNext(Node* next);
	    void SetPair(std::string key, std::string password);
	    std::string GetKey();
	    std::string GetPass();
	    Node* GetNext();
};


#endif
