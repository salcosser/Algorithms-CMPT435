#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include <algorithm> 

//std::string arr[len];
//auto *arr = new std::vector<std::string>;
//void setup()
//{
//	std::fstream newfile;
//
//	std::string ln;
//	int count = 0;

//	newfile.open("magicitems.txt", std::ios::in);
//	if (newfile.is_open())
//	{
//		
//		while (getline(newfile, ln))
//			//arr[cnt++] = ln;
//			arr->push_back(ln);
//	}
//	newfile.close();
//	return;
//}



const int len = 666;
std::string arr[len];

void setup()
{
	std::fstream newfile;

	std::string ln;
	int count = 0;

	newfile.open("magicitems.txt", std::ios::in);
	if (newfile.is_open())
	{
		while (getline(newfile, ln)) {

			transform(ln.begin(), ln.end(), ln.begin(), ::tolower);
			//std::cout << ln << std::endl;
			arr[count++] = ln;
		}
		
			


	}
	newfile.close();
	return;
}

void reset() {
	for (std::string s : arr) {
		s = "";
	}
	std::cout << "-----------------------Resetting-------------------------" << std::endl;
}









int main() {
	setup();
	std::cout << "Insertion sort made " << std::to_string(Sort::Insertion(arr, len)) << " comparisons."<<std::endl;
	reset();

	setup();
	std::cout << "Selection sort made " << std::to_string(Sort::Selection(arr, len)) << " comparisons." <<std::endl;
	reset();

	setup();
	int cnt = 0;
	Sort::mergeSort(arr, 0, (len - 1), cnt);
	std::cout << "Merge sort made " << std::to_string(cnt) << " comparisons." << std::endl;
	


}