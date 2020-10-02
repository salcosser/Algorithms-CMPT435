#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include <algorithm>
#include <thread>
#include <chrono>

const int len = 666; //finishes in ~15 - 35 ms

std::string arr[4][len];	//cleaner way than resetting the array each time

void setup()
{
	for (int i = 0; i < 4; i++)	//one iteration for each sub array
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

				arr[i][count++] = ln;		//place the line
			}
		}
		newfile.close();
	}

	return;
}

int main()
{
	setup();
	std::cout << "Insertion sort made " << std::to_string(Sort::Insertion(arr[0], len)) << " comparisons." << std::endl;

	std::cout << "Selection sort made " << std::to_string(Sort::Selection(arr[1], len)) << " comparisons." << std::endl;

	int cnt = 0;	//need to do this as recursive functions cannot easily maintain state through iterations
	Sort::mergeSort(arr[2], 0, (len - 1), cnt);
	std::cout << "Merge sort made " << std::to_string(cnt) << " comparisons." << std::endl;

	int qCnt = 0; //need to do this as recursive functions cannot easily maintain state through iterations
	Sort::quickSort(arr[3], 1, len, qCnt);
	std::cout << "Quick sort made " << std::to_string(qCnt) << " comparisons." << std::endl;
	/* Sort::printList(arr[0], len); //test Insertion Sort
	Sort::printList(arr[1], len); //test Selection Sort
	Sort::printList(arr[2], len); //test Merge Sort
	Sort::printList(arr[3], len); //test Quick Sort */
}
