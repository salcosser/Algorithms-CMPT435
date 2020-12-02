
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
#include <limits>
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
cout << "**********************************"<<endl;
					Bellman();
cout << "**********************************"<<endl;
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

								Edge *e = new Edge();
								e->weight = weight;
								e->dest = graph[j];
								e->from = graph[i];
								//cout  << num1 << " , "<< num2 << "|" << weight << endl;
								weightMatrix.push_back(e);
								//graph[i]->dests.push_back(e);
							}
						}
					}
				}
			}
		}
	}
	newfile.close();

	return;
};

void GraphManager::init(Vertex *source)
{
	for (int i = 0; i < graph.size(); i++)
	{
		graph[i]->distance = 10000000;
		graph[i]->prev = nullptr;
	}
	source->distance = 0;
	//cout << "source dist has been initialized to "<< source->distance << endl;
}

void GraphManager::relax(Edge *edge, Vertex *from, Vertex *dest)
{
	if (dest->distance > from->distance + edge->weight)
	{
		dest->distance = from->distance + edge->weight;
		dest->prev = from;
	}
}

bool GraphManager::Bellman()
{
	init(graph[0]);
	for (int i = 0; i < graph.size(); i++)
	{
		for (Edge *e : weightMatrix)
		{
			relax(e, e->from, e->dest);
		}
	}
	for (int q = 0; q < weightMatrix.size(); q++)
	{
		if (weightMatrix[q]->dest->distance > weightMatrix[q]->from->distance + weightMatrix[q]->weight)
		{
			cout << "Uh Oh! Found a negative cycle!" << endl;
			return false;
		}
	}

	for (int n = 1; n < graph.size(); n++)
	{
		printPath(graph[0], graph[n]);
	}

	return true;
}

void GraphManager::printPath(Vertex *source, Vertex *dest)
{
	vector<Vertex *> traceback;
	cout << source->id << "->" << dest->id << " cost is " << dest->distance << "; path: ";
	bool found = false;
	Vertex *currentV = dest;
	while (!found)
	{
		if (currentV->id != source->id)
		{
			//cout << "HERE" <<endl;
			traceback.push_back(currentV);
			currentV = currentV->prev;
		}
		else
		{
			//cout << "ALSO HERE" <<endl;
			found = true;
		}
	}
	cout << source->id;
	//cout << traceback.size() << endl;
	for (int i = traceback.size() - 1; i >= 0; i--)
	{
		cout << "->" << traceback[i]->id;
	}
	cout << endl;
}
