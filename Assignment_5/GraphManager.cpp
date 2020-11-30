
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include "GraphManager.h"
#include "Vertex.h"


using namespace std;
void GraphManager::fileReader(std::string fileName)
{

	fstream newfile;

	string ln;
	int count = 0;
	bool started = false;
	newfile.open(fileName,ios::in);
	if (newfile.is_open())
	{
		while (getline(newfile, ln)) //read each line of the file
		{

			if (ln.find("new graph") != string::npos)
			{

				if (started)
				{
					cout << "To Doing Stuff" <<endl;
					/**
					 * SSSP stuff
					 * 
					 * 
					 * 
					 * */
					graph.clear();		//restarting the graph
				}
				started = true;
			}
			else if (ln.find("add vertex") != string::npos)
			{
				int id = stoi(ln.substr(11));
				Vertex *vertex = new Vertex();
				vertex->id = id;
				graph.push_back(vertex);			//make a vertex with an id of the number on the line
			}
			else if (ln.find("add edge") != string::npos)
			{

				int hyph = ln.find("-");

				int num1 = stoi(ln.substr((ln.find("edge") + 5), 2));					//grabbing both numbers out
				int num2 = stoi(ln.substr(hyph + 2, 2));
				int weight = stoi(ln.substr(hyph + 4));

				for (int i = 0; i < graph.size(); i++)				//using two different "fingers" on the vector at a time
				{
					if (graph[i]->id == num1)
					{
						for (int j = 0; j < graph.size(); j++)
						{
							if (graph[j]->id == num2)
							{
								//graph[i]->neighbors.push_back(graph[j]);			//a neighbor of b,  b neighbor of a
								//graph[j]->neighbors.push_back(graph[i]);
								Edge * e = new Edge();
								e->weight = weight;
								e->dest = graph[j];
								graph[i]->edges.push_back(e);
							}
						}
					}
				}
			}
		}
	}
	newfile.close();
	cout <<"NOTHING BROKE!!!"<<endl;
	return;
};

