#pragma once
#include <iostream>
#include <string>
#include <vector>
class Sort {
public:


	static void swap(std::string &a, std::string &b);
	static void printList(std::string s[], int n);
	static int Insertion(std::string s[], int n);
	static int Selection(std::string s[], int n);
};