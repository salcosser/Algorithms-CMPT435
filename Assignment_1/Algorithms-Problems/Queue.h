#pragma once
#include "Node.h"
#include <string>
class Queue {
public:
	Node* head;
	Node* tail;
	void enQueue(std::string s);
	Node deQueue();
	bool isEmpty();
};