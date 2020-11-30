
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include "GraphManager.h"
#include "Vertex.h"
#include "Edge.h"
#include <math.h>
using namespace std;
void GraphManager::fileReader(std::string fileName)
{

	fstream newfile;

	string ln;
	int count = 0;
	bool started = false;
	newfile.open(fileName, ios::in);
	if (newfile.is_open())
	{
		while (getline(newfile, ln)) //read each line of the file
		{

			if (ln.find("new graph") != string::npos)
			{

				if (started)
				{
					cout << "To Doing Stuff" << endl;
					/**
					 * SSSP stuff
					 * 
					 * 
					 * 
					 * */

				

					cout  << graph.size()<< "|" << weightMatrix.size() << endl;




					weightMatrix.clear();
					graph.clear(); //restarting the graph
				}
				started = true;
			}
			else if (ln.find("add vertex") != string::npos)
			{
				int id = stoi(ln.substr(11));
				Vertex *vertex = new Vertex();
				vertex->id = id;
				graph.push_back(vertex); //make a vertex with an id of the number on the line
			}
			else if (ln.find("add edge") != string::npos)
			{

				int hyph = ln.find("-");

				int num1 = stoi(ln.substr((ln.find("edge") + 5), 2)); //grabbing both numbers out
				int num2 = stoi(ln.substr(hyph + 2, 2));
				int weight = stoi(ln.substr(hyph + 4));
				bool foundMatches = false;
				for (int i = 0; i < graph.size(); i++) //using two different "fingers" on the vector at a time
				{
					if (graph[i]->id == num1)
					{
						for (int j = 0; j < graph.size(); j++)
						{
							if (graph[j]->id == num2)
							{
								//graph[i]->neighbors.push_back(graph[j]);			//a neighbor of b,  b neighbor of a
								//graph[j]->neighbors.push_back(graph[i]);
								Edge *e = new Edge();
								e->weight = weight;
								e->dest = graph[j];
								e->from = graph[i];
								
								weightMatrix.push_back(e);
								graph[i]->dests.push_back(e);
							}
						}
					}
				}
			}
		}
	}
	newfile.close();
	cout << "Vertices" << endl;
		
					cout << graph.size() << "|"<<  weightMatrix.size() << endl;
	cout << "NOTHING BROKE!!!" << endl;
	return;
};

   void GraphManager::init(Vertex * source){
	   	for(int i = 0;i<graph.size();i++){
			   graph[i]->distance = INFINITY;
				graph[i]->prev = nullptr;
			
		   }
		   source->distance = 0; 
   }


void GraphManager::relax(Edge * edge){
	if(edge->dest->distance > edge->from->distance + edge->weight){
		edge->dest->distance = edge->from->distance + edge->weight;
		edge->dest->prev = edge->from;
	}

}

bool GraphManager::Bellman(){
	init(graph[0]);
	for(int i = 0;i<graph.size();i++){
		for(int j = 0;j<weightMatrix.size();j++){
			relax(weightMatrix[j]);
		}
	}
	for(int q=0;q<weightMatrix.size();q++){
		if(weightMatrix[q]->dest->distance > weightMatrix[q]->from->distance + weightMatrix[q]->weight){
			cout << "Uh Oh! Found a negative cycle!" << endl;
			return false;
		}
	}
	cout << "Nothing went wrong!"<<endl;
	return true;
}

