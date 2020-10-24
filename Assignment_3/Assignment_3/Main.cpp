#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include "Search.h"
#include "HashTable.h"

#include <algorithm>
const int len = 666; //finishes in ~15 - 35 ms
const int chosenLen = 42;
std::string arr[len];	//cleaner way than resetting the array each time

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
	
	Sort::mergeSort(arr, 0, (len - 1));
	return;
}

void HashTheTable(std::string arr[], int len) {
	HashTable* tab = new HashTable();
	
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
	std::string items[chosenLen];
	Search::randPick(arr, items,len,  42);
	int linAvg = Search::linSearch(arr, len, items, chosenLen);
	int binAvg = Search::binSearch(arr, len, items, 42);
	std::cout << "Linear Search:||: Average comparisons before a hit: " << linAvg << std::endl;
	std::cout << "Binary Search:||: Average comarisons before a hit: " << binAvg  << std::endl;
	HashTheTable(arr, len);
	
}
