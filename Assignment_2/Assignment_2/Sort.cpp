#include "Sort.h"
#include <iostream>
#include <string>

#include <algorithm>

void Sort::swap(std::string &a, std::string &b) //simple function to swap strings
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

int Sort::Insertion(std::string s[], int n)
{
	int counter = 0;
	std::string last;
	for (int i = 1; i < n; i++)
	{
		last = s[i]; //mark the current thing to be compared against
		int j = i - 1;
		while (j >= 0 && s[j] > last) // compare all other elements below to see which is smaller
		{
			counter++;

			s[j + 1] = s[j]; //keep moving the compared index up

			j--;
		}

		s[j + 1] = last; //once an element's space is created place it in the correct place
	}

	//printList(s, n);		//debugging
	return counter;
}

int Sort::Selection(std::string s[], int n)
{
	int low;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		low = i; //assume that the current index is the lowest value
		for (int j = i + 1; j < n; j++)
		{
			counter++;

			if (s[j] < s[low]) //for every element after i, compare it to what is currently believed to be the lowest value
			{
				low = j; //if a new lower element is found, mark it as the new lowest
			}
		}
		Sort::swap(s[low], s[i]); //after processing all elements, move the current lowest element into the place of i
	}
	//printList(s, n);		//debugging
	return counter;
}

int Sort::subMSort(std::string s[], int l, int m, int r, int cnt)
{
	int counter = 0;
	int len1 = m - l + 1; //create two sub arrays of the correct sizes
	int len2 = r - m;

	std::string *left = new std::string[len1];
	std::string *right = new std::string[len2];

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
			counter++;
		}
		else
		{
			s[k++] = right[j++];
			counter++;
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
	return counter;
}

void Sort::mergeSort(std::string s[], int lInd, int rInd, int &cnt)
{

	int m = 0;

	if (lInd < rInd) //as long as the left and right index account for a proper merge sort
	{
		m = lInd + (rInd - lInd) / 2; //declare the midpoint and do a merge sort on both halves of the array
		mergeSort(s, lInd, m, cnt);
		mergeSort(s, (m + 1), rInd, cnt);

		cnt += Sort::subMSort(s, lInd, m, rInd, cnt); //sort the array
	}
	else
	{
		//int n = sizeof(*s) / sizeof(s[0]);
		//printList(s, n);
	}
}

void Sort::quickSort(std::string s[], int p, int r, int &cnt)
{
	if (p < r)			//validate the length of the array bounds
	{
		int q = Sort::Partition(s, p, r, cnt);		//return the new midpoint after partitioning
		Sort::quickSort(s, p, (q - 1), cnt);		//run quick sort on both halves of the array
		Sort::quickSort(s, (q + 1), r, cnt);
	}
}

int Sort::Partition(std::string s[], int p, int r, int &cnt)
{
	std::string x = s[r];			//grab the last element in the given bounds as the pivot value
	int i = p - 1;					// set the current starting midpoint / last sorted item
	for (int j = p; j < (r - 1); j++)		//begin iterating at the low bound point, and continue until 1 before the high bound
	{
		if (s[j] <= x)			//check if the current iterated value is lower or equal to the pivot point
		{
			i++;				//move the midpoint up
			cnt++;
			Sort::swap(s[i], s[j]);			//place the new found low item in its correct place
		}
		else
		{
			cnt++;
		}
	}
	Sort::swap(s[(i + 1)], s[r]);	//swap the last element and the element right after the last sorted item
	return ++i;		//return the index after the last sorted item
}
