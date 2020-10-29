#include "Search.h"
#include <string>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
void  Search::randPick(std::string mainArr[], std::string chosen[], int len,  int lenOfChosen)
{

	int countTries = 0;
	
	for (int i = 0; i < lenOfChosen; i++) {



		bool same = true;
		while (same) {
			std::random_device dev;	//making the random number
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(0, len);



			std::string attempt = mainArr[dist6(rng)];
			// std::cout << attempt << std::endl;
			bool foundSame = false;
			for (int j = 0; j < lenOfChosen;j++) {

				if (chosen[j] == attempt) {
					
					countTries++;
					foundSame = true;
					break;
				}
			}

			if (foundSame) {
				
				countTries++;
				continue;
			}

			else {
				
				countTries++;
				chosen[i] = attempt;
				same = false;
			}

		}
		
		}
	
	return;
	}

int Search::linSearch(std::string mainArr[],int len, std::string chosen[], int lenOfChosen)
{
	std::cout << "---Linear Search---"<<std::endl;
	int tCount = 0;
	
	for (int i = 0; i < lenOfChosen; i++) {
		int count = 0;
		for (int j = 0; j < len; j++) {
			if (mainArr[j] != chosen[i]) {
				count++;
			}
			else {
				std::cout << "Found it at index " << j <<  " after "<< count << " checks." <<std::endl;
				
				tCount += ++count;
				
					
				break;
			}
		}
	}
	
	int avg = (int)(tCount / lenOfChosen);
	return avg;
}

int Search::binSearch(std::string mainArr[], int len, std::string chosen[], int lenOfChosen)
{
	std::cout << "---Binary Search---" << std::endl;
	int tCount = 0;
	
	for (int x = 0; x < lenOfChosen; x++) {

		
		int count = 0;
		int low = 0;
		int high = len;
		bool found = false;
		while (!found) {
			
			int mid = (int)floor((low + high) / 2);
			if (chosen[x] < mainArr[mid]) {
				count++;
				high = mid;
			}
			else if (chosen[x] > mainArr[mid]) {
				count++;
				low = mid++;
			}
			else {
			
				tCount += ++count;
				std::cout << "found it at index " << high << " after " << count << " tries." << std::endl;
				found = true;
			}
		}
		
	}
	int avg = (int)(tCount / lenOfChosen);
	return avg;
	
}

