#pragma once
#include <iostream>
#include <string>
#include "Node.h"
class Stack {
public:
	Node* top;
	bool isEmpty();
	void push(std::string arg);
	Node pop();
};
