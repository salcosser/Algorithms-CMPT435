
#include <iostream>
#include <string>
#include "GraphManager.h"
#include "Greedy.h"
using namespace std;

int main()
{

	cout << "---------RUNNING BELLMAN-FORD SSSP----------" << endl;
	GraphManager *gm = new GraphManager();
	gm->fileReader("graphs2.txt"); //create the graph and process it
	cout << "---------RUNNING FRACTIONAL KNAPSACK----------" << endl;
	Greedy *greed = new Greedy();
	greed->setupSpices("spice.txt"); //run fractional knapsack
	return 0;
}