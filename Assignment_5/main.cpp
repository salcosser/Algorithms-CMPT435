
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <random>
#include "GraphManager.h"
#include "Greedy.h"
using namespace std;

int main()
{

	GraphManager *gm = new GraphManager();
	gm->fileReader("graphs2.txt"); //create the graph and process it
	gm->Bellman();
	Greedy * greed = new Greedy();
	greed->setupSpices("spice.txt");
	return 0;
}