#include "Sort.h"
#include <iostream>
#include <string>

#include <algorithm>

void Sort::swap(std::string &a, std::string &b)
{
	std::string temp = a;
	a = b;
	b = temp;
}

void Sort::printList(std::string s[], int n)
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
		last = s[i];
		int j = i - 1;
		while (j >= 0 && s[j] > last)
		{
			counter++;

			s[j + 1] = s[j];

			j--;
		}

		s[j + 1] = last;
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
		low = i;
		for (int j = i + 1; j < n; j++)
		{
			counter++;

			if (s[j] < s[low])
			{
				low = j;
			}
		}
		Sort::swap(s[low], s[i]);
	}
	//printList(s, n);		//debugging
	return counter;
}

int Sort::subMSort(std::string s[], int l, int m, int r, int cnt)
{
	int counter = 0;
	int len1 = m - l + 1;
	int len2 = r - m;

	std::string *left = new std::string[len1];
	std::string *right = new std::string[len2];

	for (int i = 0; i < len1; i++)
	{
		left[i] = s[l + i];
	}
	for (int j = 0; j < len2; j++)
	{
		right[j] = s[m + 1 + j];
	}
	int i = 0, j = 0;
	int k = l;
	while (i < len1 && j < len2)
	{

		counter++;
		s[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
	}
	while (i < len1)
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

	if (lInd < rInd)
	{
		m = lInd + (rInd - lInd) / 2;
		mergeSort(s, lInd, m, cnt);
		mergeSort(s, (m + 1), rInd, cnt);

		cnt += Sort::subMSort(s, lInd, m, rInd, cnt);
	}
	else
	{
		//int n = sizeof(*s) / sizeof(s[0]);
		//printList(s, n);
	}
}

void Sort::quickSort(std::string s[], int p, int r, int &cnt)
{
	if (p < r)
	{
		int q = Sort::Partition(s, p, r, cnt);
		Sort::quickSort(s, p, (q - 1), cnt);
		Sort::quickSort(s, (q + 1), r, cnt);
	}
}

int Sort::Partition(std::string s[], int p, int r, int &cnt)
{
	std::string x = s[r];
	int i = p - 1;
	for (int j = p; j < (r - 1); j++)
	{
		if (s[j] <= x)
		{
			i++;
			cnt++;
			Sort::swap(s[i], s[j]);
		}else{
			cnt++;
		}
	}
	Sort::swap(s[(i + 1)], s[r]);
	return ++i;
}
