#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Spice.h"
using namespace std;
class Sort			//stripped down version of sort class
{
public:
	
	static void printList(vector<Spice *> s, int n);
	static void subMSort(vector<Spice *> s, int l, int m, int r);		//sorting part of Merge Sort		counters have been stripped
	static void mergeSort(vector<Spice *> s, int lInd, int rInd);	//recursive part of Merge Sort
};