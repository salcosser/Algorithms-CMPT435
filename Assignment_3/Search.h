#pragma once
#include <string>
class Search {
public:
	static void randPick(std::string mainArr[],std::string chosen[], int len, int lenOfChosen);
	static int linSearch(std::string mainArr[], int len, std::string chosen[], int lenOfChosen);
	static int binSearch(std::string mainArr[], int len, std::string chosen[], int lenOfChosen);
};