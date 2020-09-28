#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include <cassert>
#include <vector>


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
		while (getline(newfile, ln))
			//arr[cnt++] = ln;
			arr[count++] = ln;
	}
	newfile.close();
	return;
}

void reset() {
	for (std::string s : arr) {
		s = "";
	}
}









int main() {
	setup();
	
	std::cout << "Insertion sort made " << std::to_string(Sort::Insertion(arr, len)) << " comparisons."<<std::endl;
	reset();
	setup();
	//std::cout << "------------------------------pre-----------" << arr->size() << "-------------" << std::endl;
	std::cout << "Selection sort made " << std::to_string(Sort::Selection(arr, len)) << " comparisons." <<std::endl;
	
	//std::cout << arr.at(665) << std::endl;
	


}