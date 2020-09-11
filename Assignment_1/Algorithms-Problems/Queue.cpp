#include <iostream>
#include <string>
#include "Queue.h"

void Queue::enQueue(std::string s) {
	
	if (tail == nullptr) {
		std::cout << "**First**" << std::endl;
		Node* n = new Node();
		n->data = s;
		tail = n;
		head = n;
	}
	else {
		std::cout << "**Another**" << std::endl;
		Node* t = new Node();
		t->data = s;
		tail->next = t;
		tail = t;
				
	}
	return;

}
bool Queue::isEmpty() {
	if (tail == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
Node Queue::deQueue() {
	if (isEmpty()) {
		throw "Memory Underflow Error";
	}
	else {
		Node n = Node(*head);
		if (head->next != nullptr) {
			Node* newHead = head->next;
			head = newHead;
			return n;
		}
		else {
			return n;
		}
	}
	
	
}