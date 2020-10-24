#pragma once
#include <string>
#include <iostream>

class Node
{ // defining class for the node that has the pointer and the data
public:
	std::string data; // stores data for the node
	Node* next = nullptr;		  // stores pointer for the node
};
