#pragma once
#include <string>
#include <iostream>
#include "Vertex.h"
class Node
{ // defining class for the node that has the pointer and the data
public:
	Vertex* data; // stores data for the node
	Node* next = nullptr;		  // stores pointer for the node
};
