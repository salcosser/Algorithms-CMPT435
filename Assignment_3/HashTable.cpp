#include "HashTable.h"
#include <iostream>
#include <algorithm>
int HashTable::getHash(std::string item)
{
	std::transform(item.begin(), item.end(), item.begin(), ::toupper);
	int sLen = item.length();
	int letterTotal = 0;
	for (int i = 0; i < sLen; i++)
	{
		char thisLetter = item[i];
		int thisValue = (int)thisLetter;
		letterTotal += thisValue;
	}
	int hashCode = (letterTotal * 1) % HASH_TABLE_SIZE;
	//std::cout << hashCode << std::endl;
	return hashCode;
}

void HashTable::placeHashed(std::string item)
{
	int hash = getHash(item);
	table[hash].enQueue(item);
}

void HashTable::visualize()
{
	std::cout << "---visualizing your data---" << std::endl;

	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{ //getting the data

		if (table[i].head == nullptr)
		{
			std::cout << i << "|" << std::endl;

			
		}
		else
		{
			std::cout << i << "|";
			Node *start = table[i].head;
			while (start != nullptr)
			{
				std::cout << "*";
				start = start->next;
			}
			std::cout << std::endl;
		}
	}
}
int HashTable::getHashed(std::string items[], int chosenLen)
{
	std::cout << "--Retrieving hashed Data--" << std::endl;
	int tCount = 0;

	for (int i = 0; i < chosenLen; i++)
	{
		int count = 0;

		int hashLoc = getHash(items[i]);

		Queue chain = table[hashLoc];

		Node *n = chain.head;
		//std::cout << n->data << std::endl; uncomment to see the data
		if (n->data == "")
		{
			std::cout << "If you're seeing this, the list is empty." << std::endl;
		}
		else
		{
			while (n->data != items[i])
			{
				count++;
				n = n->next;
			}

			std::cout << "Found it at place " << ++count << " in the chain." << std::endl;
			tCount += count; //take off the pre increment if uncommenting above line
		}
	}
	int avg = tCount / chosenLen;
	return avg;
}
