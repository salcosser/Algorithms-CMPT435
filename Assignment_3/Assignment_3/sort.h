#pragma once
#include <iostream>
#include <string>

class Sort			//stripped down version of sort class
{
public:
	static void swap(std::string& a, std::string& b);
	static void printList(std::string s[], int n);
	static void subMSort(std::string s[], int l, int m, int r);		//sorting part of Merge Sort		counters have been stripped
	static void mergeSort(std::string s[], int lInd, int rInd);	//recursive part of Merge Sort
};