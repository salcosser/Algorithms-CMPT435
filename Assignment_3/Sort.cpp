#include "Sort.h"
#include <iostream>
#include <string>

#include <algorithm>

void Sort::swap(std::string& a, std::string& b) //simple function to swap strings
{
	std::string temp = a;
	a = b;
	b = temp;
}

void Sort::printList(std::string s[], int n) //function that iterates over the array and prints out each line
{
	for (int i = 0; i < n; i++)
	{
		std::cout << s[i] << std::endl;
	}
}



void Sort::subMSort(std::string s[], int l, int m, int r)
{
	
	int len1 = m - l + 1; //create two sub arrays of the correct sizes
	int len2 = r - m;

	std::string* left = new std::string[len1];
	std::string* right = new std::string[len2];

	for (int i = 0; i < len1; i++) //allocate the values of the larger array into their corresponding places in one of the two halves
	{
		left[i] = s[l + i];
	}
	for (int j = 0; j < len2; j++)
	{
		right[j] = s[m + 1 + j];
	}
	int i = 0, j = 0;
	int k = l;
	while (i < len1 && j < len2) //place the lower of the values between both arrays at a given index next in place in the parent array
	{
		if (left[i] < right[j])
		{
			s[k++] = left[i++];
			
		}
		else
		{
			s[k++] = right[j++];
			
		}
	}
	while (i < len1) //tack on the unsorted items to the end of the array
	{
		s[k++] = left[i++];
	}
	while (j < len2)
	{
		s[k++] = right[j++];
	}

}

void Sort::mergeSort(std::string s[], int lInd, int rInd)
{

	int m = 0;

	if (lInd < rInd) //as long as the left and right index account for a proper merge sort
	{
		m = lInd + (rInd - lInd) / 2; //declare the midpoint and do a merge sort on both halves of the array
		mergeSort(s, lInd, m);
		mergeSort(s, (m + 1), rInd);

	 Sort::subMSort(s, lInd, m, rInd); //sort the array
	}
	else
	{
		//int n = sizeof(*s) / sizeof(s[0]);
		//printList(s, n);
	}
}


