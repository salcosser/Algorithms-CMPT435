
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <random>
#include "BinTree.h"
#include "GraphManager.h"
using namespace std;

const int MAGIC_LEN = 666; //finishes in ~15 - 35 ms
const int CHOSEN_LEN = 42;
std::string arr[MAGIC_LEN];	


void setupMagic()
{
	
		std::fstream newfile;

		std::string ln;
		int count = 0;

		newfile.open("magicitems.txt", std::ios::in);
		if (newfile.is_open())
		{
			while (getline(newfile, ln))	//read each line of the file
			{

				transform(ln.begin(), ln.end(), ln.begin(), ::tolower);	//make it all lower case to normalize it

				arr[count++] = ln;		//place the line
			}
		}
		newfile.close();
	
	
	return;
}










void populateTree(BinTree * tree, std::string arr[], int arrLen){
    for(int i = 0; i<arrLen;i++){
   
       tree->insert(arr[i]);
	 //  cout << "inserted "<< arr[i] << endl;
    }
}

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
int main(){
	setupMagic();
    BinTree * tree = new BinTree();
    populateTree(tree, arr, MAGIC_LEN);
	string randItems[CHOSEN_LEN];
	randPick(arr, randItems, MAGIC_LEN, CHOSEN_LEN);
	// for(string s : randItems){
	// 	cout << s << endl;
	// }
	tree->pullBatch(randItems, CHOSEN_LEN);
	GraphManager * gm = new GraphManager();
	gm->Overlord("graphs1.txt");


}