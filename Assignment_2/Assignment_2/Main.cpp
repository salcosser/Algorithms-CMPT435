#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include <algorithm>
#include <thread>
#include <chrono>

const int len = 666; //normal mode  finishes in ~15 - 35 ms

std::string arr[4][len];
//std::string arr[len];
void setup()
{
	for (int i = 0; i < 4; i++)
	{
		std::fstream newfile;

		std::string ln;
		int count = 0;

		newfile.open("magicitems.txt", std::ios::in); //normal mode
		if (newfile.is_open())
		{
			while (getline(newfile, ln))
			{

				transform(ln.begin(), ln.end(), ln.begin(), ::tolower);

				arr[i][count++] = ln;
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

	int cnt = 0;
	Sort::mergeSort(arr[2], 0, (len - 1), cnt);
	std::cout << "Merge sort made " << std::to_string(cnt) << " comparisons." << std::endl;

	int qCnt = 0;
	Sort::quickSort(arr[3], 1, len, qCnt);
	std::cout << "Quick sort made " << std::to_string(qCnt) << " comparisons." << std::endl;
	/* Sort::printList(arr[0], len); //test Insertion Sort
	Sort::printList(arr[1], len); //test Selection Sort
	Sort::printList(arr[2], len); //test Merge Sort
	Sort::printList(arr[3], len); //test Quick Sort */
}
