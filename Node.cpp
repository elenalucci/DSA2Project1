#include "Node.hpp"

Node::Node(std::string key, std::string password){
	this->key = key;
	this->password = password;
	this->next = nullptr;
}

void Node::SetNext(Node* next){

	this->next = next;

}

void Node::SetPair(std::string key, std::string password){
	
	this->key = key;
	this->password = password;

}

std::string Node::GetKey(){
	return key;
}

std::string Node::GetPass(){
	return password;
}

Node* Node::GetNext(){
	return next;
}
