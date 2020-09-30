#pragma once
#include <iostream>
#include <string>

class Sort
{
public:
	static void swap(std::string &a, std::string &b);
	static void printList(std::string s[], int n);
	static int Insertion(std::string s[], int n);
	static int Selection(std::string s[], int n);
	static int subMSort(std::string s[], int l, int m, int r, int cnt);
	static void mergeSort(std::string s[], int lInd, int rInd, int &cnt);
	static void quickSort(std::string s[], int p, int r, int &cnt);
	static int Partition(std::string s[], int p, int r, int &cnt);
};