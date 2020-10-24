#include "HashTable.h"
#include <iostream>
#include <algorithm>
int HashTable::getHash(std::string item)
{
	std::transform(item.begin(), item.end(), item.begin(), ::toupper);
	int sLen = item.length();
	int letterTotal = 0;
	for (int i = 0; i < sLen; i++) {
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

	for (int i = 0; i < HASH_TABLE_SIZE; i++) {	//getting the data
	
		if (table[i].head == nullptr)
		{
			std::cout << i << "|" << std::endl;

			continue;
		}
		else
		{
			std::cout << i << "|";
			Node* start = table[i].head;
			while (start != nullptr)
			{
				std::cout << "*";
				start = start->next;
			}
			std::cout << std::endl;
		}
	}
	


}