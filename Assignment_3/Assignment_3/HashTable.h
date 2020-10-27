#pragma once
#include "Node.h"
#include "Queue.h"
class HashTable {
public:
	static const int HASH_TABLE_SIZE = 250;
	Queue table[HASH_TABLE_SIZE];
	static int getHash(std::string item);
	void placeHashed(std::string item);
	int getHashed(std::string items[], int chosenLen);
	void visualize();
};