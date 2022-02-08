//Elena Lucci COP4534
#include "Node.hpp"
//default constructor creates node
Node::Node(std::string key, std::string password){
	this->key = key;
	this->password = password;
	this->next = nullptr;
}
//sets next node
void Node::SetNext(Node* next){

	this->next = next;

}
// sets key and password values
void Node::SetPair(std::string key, std::string password){
	
	this->key = key;
	this->password = password;

}
//returns last name
std::string Node::GetKey(){
	return key;
}
//returns password
std::string Node::GetPass(){
	return password;
}
//returns next node
Node* Node::GetNext(){
	return next;
}
