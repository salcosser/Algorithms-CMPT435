
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <random>
#include "GraphManager.h"
using namespace std;

void randPick(std::string mainArr[], std::string chosen[], int len, int lenOfChosen)
{

	int countTries = 0;

	for (int i = 0; i < lenOfChosen; i++)
	{

		std::random_device dev; //making the random number
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(0, len);

		std::string attempt = mainArr[dist6(rng)];

		chosen[i] = attempt; //if there were no matches, then add it to the list
	}
}
int main()
{

	GraphManager *gm = new GraphManager();
	gm->fileReader("graphs2.txt"); //create the graph and process it
	return 0;
}