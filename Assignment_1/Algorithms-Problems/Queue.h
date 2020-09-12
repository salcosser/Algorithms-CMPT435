#pragma once
#include "Node.h"
#include <string>
class Queue {	// header class to define the queue class
public:
	Node* head;						//pointer to the head node
	Node* tail;						//pointer to the tail node
	void enQueue(std::string s);	//function which adds a node to the queue
	Node deQueue();					//function to take a node off  of the queue
	bool isEmpty();					//tests if the queue is empty
};