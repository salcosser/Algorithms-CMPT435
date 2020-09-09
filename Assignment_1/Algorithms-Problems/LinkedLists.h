#pragma once
#include <string>
#include <iostream>
class Node{
public:
	std::string data;
	Node* next = nullptr;
	Node() {};
	
};



class Stack {
public:
	Node* top;
	bool isEmpty();
	void push(std::string arg);
	Node pop();
};
