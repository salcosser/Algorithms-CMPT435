#include <iostream>
#include <string>
#include "Queue.h"
// For cleanliness, inline comments in implementation are moved to the documentation
void Queue::enQueue(std::string s)
{

	if (isEmpty())
	{

		Node* n = new Node();
		n->data = s;
		tail = n;
		head = n;
	}
	else
	{

		Node* t = new Node();
		t->data = s;
		tail->next = t;
		tail = t;
	}
	return;
}
bool Queue::isEmpty()
{
	if (tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Node Queue::deQueue()
{
	if (isEmpty())
	{
		throw "Memory Underflow Error";
	}
	else
	{
		Node n = Node(*head);
		if (head->next != nullptr)
		{
			Node* newHead = head->next;
			head = newHead;
			return n;
		}
		else
		{
			head = nullptr;
			tail = nullptr;
			return n;
		}
	}
}