#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <fstream>
#include <string>
#include <cassert>
using namespace std;
// For cleanliness, inline comments in implementation are moved to the documentation
void printList(Node *e)
{
	if (e == nullptr)
	{
		std::cout << "If you're seeing this, the list is empty." << std::endl;
		return;
	}
	else
	{
		while (e != nullptr)
		{
			std::cout << e->data << " ";
			e = e->next;
		}
		cout << endl;
		return;
	}
}
void LinkedListDemo()
{
	std::cout << "This is a demonstration of a linked list" << std::endl;
	//Node a, b, c;
	Node *a = new Node();
	Node *b = new Node();
	Node *c = new Node();
	a->data = "Sam";
	a->next = b;
	b->data = "Bill";
	b->next = c;
	c->data = "Sean";
	c->next = nullptr;
	printList(a);
	return;
}
void StackDemo()
{
	Stack stack = Stack();
	stack.push("Ethan");
	stack.push("Donnavan");
	stack.push("Kayla");
	cout << "This is a demo of a Stack." << endl;
	cout << "I have pushed three elements to the stack, Ethan, Donnavan, and Kayla in that order, and this is what the stack looks like now." << endl;
	printList(stack.top);
	cout << stack.pop().data << endl;
	cout << stack.pop().data << endl;
	cout << stack.pop().data << endl;
	cout << "I just popped off the top of the stack. Here's what it looks like now." << endl;

	printList(stack.top);
	return;
}
void QueueDemo()
{
	Queue q = Queue();
	cout << "And now, here's the queue demo." << endl;
	q.enQueue("Mark");
	cout << "Mark has been added" << endl;
	q.enQueue("Dylan");
	cout << "Dylan has been added" << endl;
	q.enQueue("Rachel");
	cout << "Rachel has been added" << endl;
	q.enQueue("Mike");
	cout << "Mike has been added" << endl;
	cout << "as of right now, the list looks like this:" << endl;
	printList(q.head);
	cout << "And now, I will take off everyone in the line ( Hopefully starting with Mark)." << endl;
	cout << q.deQueue().data << endl;
	cout << q.deQueue().data << endl;
	cout << q.deQueue().data << endl;
	printList(q.head);
}

void AlanParse()
{
	fstream newfile;
	string arr[1000];
	string ln;
	int count = 0;
	int pCount = 0;
	newfile.open("magicitems.txt", ios::in);
	if (newfile.is_open())
	{
		int cnt = 0;
		while (getline(newfile, ln))
			arr[cnt++] = ln;
		int placeHolder = 0;
		while (arr[placeHolder] != "")
		{

			//read data from file object and put it into string.
			string ogLine = arr[placeHolder];
			string line;
			Stack stack = Stack();
			Queue queue = Queue();
			int len = 0;
			for (char c : arr[placeHolder])
			{
				if (c == ' ')
				{
					continue;
				}
				else
				{
					len++;
					string temp;
					temp += toupper(c);
					stack.push(temp);
					queue.enQueue(temp);
				}
			}
			for (int i = 0; i < len; i++)
			{
				string st = stack.pop().data;
				string qu = queue.deQueue().data;

				if (st == qu)
				{
					if (i == (len - 1))
					{
						pCount++;
						std::cout << ++count << ": " << ogLine << ": is a palindrome." << endl;
					}

					continue;
				}
				else
				{
					++count;
					//cout << ++count << ":" << endl;
					//cout << st << " and " << qu << " dont match in " << line << ", so" << endl;
					//	cout << ogLine << ": is not a palindrome." << endl;
					break;
				}
			}
			placeHolder++;
		}
	}

	//checking whether the file is open

	//get size of file
	// add to array

	std::cout << "In Total, there were " << pCount << " palindromes." << endl;

	return;
}

int main()
{						
	 /*LinkedListDemo(); 		Uncomment from here to line 139 for a demo of my Linked List, Stack, and Queue
	cout << endl;		 		or just run AlanParse and trust me that it all works
	StackDemo();				&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	cout << endl;
	QueueDemo(); */
	AlanParse();
}