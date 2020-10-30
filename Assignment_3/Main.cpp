#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include "Search.h"
#include "HashTable.h"

#include <algorithm>
const int LEN = 666; //finishes in ~15 - 35 ms
const int CHOSEN_LEN = 42;
std::string arr[LEN];	//cleaner way than resetting the array each time

void setup()
{
	
		std::fstream newfile;

		std::string ln;
		int count = 0;

		newfile.open("magicitems.txt", std::ios::in);
		if (newfile.is_open())
		{
			while (getline(newfile, ln))	//read each line of the file
			{

				transform(ln.begin(), ln.end(), ln.begin(), ::tolower);	//make it all lower case to normalize it

				arr[count++] = ln;		//place the line
			}
		}
		newfile.close();
	
	Sort::mergeSort(arr, 0, (LEN - 1));
	return;
}
// loading the table up is done outside of the class itself for a reason.
// In the real world, this hash table would simply exist, and the loading process would most likely not happen all at once.
// Either way, the instantiation of the hash table and the process of loading it would undeniably take place at different times

 void hashTheTable(std::string arr[], int len, HashTable * tab) { 
 	//HashTable* tab = new HashTable();
 	for (int i = 0; i < len; i++) {
 		tab->placeHashed(arr[i]);
 	}
 	tab->visualize();
	
 }


int main()
{
	setup();
	/*for (std::string s : arr) {
		std::cout << s << std::endl;
	}*/

	// make the sorted list
	std::string items[CHOSEN_LEN];
	Search::randPick(arr, items,LEN,  42);
	int linAvg = Search::linSearch(arr, LEN, items, CHOSEN_LEN);
	int binAvg = Search::binSearch(arr, LEN, items, 42);
	std::cout << "Linear Search:||: Average comparisons to get a hit: " << linAvg << std::endl;
	std::cout << "Binary Search:||: Average comparisons to get a hit: " << binAvg  << std::endl;
	HashTable * hTable = new HashTable();
	hashTheTable(arr, LEN, hTable);
	int tCount = hTable->getHashed(items, CHOSEN_LEN);
	std::cout << "Average " << tCount << " comparisons to retrieve each item." << std::endl; 
}
