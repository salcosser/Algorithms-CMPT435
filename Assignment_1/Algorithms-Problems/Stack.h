#pragma once
#include <iostream>
#include <string>
#include "Node.h"
class Stack {
public:
	Node* top;					//points to the top node of the stack
	bool isEmpty();				//tests whether or not the stack is empty
	void push(std::string arg);	//function to add a node to the top of the stack
	Node pop();					//function to take something off of the stack
};
