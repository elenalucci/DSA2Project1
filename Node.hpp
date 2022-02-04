#ifndef NODE_HPP
#define NODE_HPP

class Node{
	
	private:
	    std::string lastName;
	    std::string password;
	    Node* next;
	    Node* prev;
	public:
	    Node(std::string lastName,std::string password);
	    Node(std::string lastName, std::string password, Node* next, Node* prev);
	    Node(std::string lastName, std::string password, Node* prev);
	    void SetNext(Node* next);
	    void SetPrev(Node* prev);
	    void SetPair(std::string lastName, std::string password);
	    
};


#endif
