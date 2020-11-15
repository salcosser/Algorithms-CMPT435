
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include "GraphManager.h"
#include "Vertex.h"
#include "Queue.h"
#include "Node.h"
void GraphManager::Overlord(std::string fileName)
{

	std::fstream newfile;

	std::string ln;
	int count = 0;
	bool started = false;
	newfile.open(fileName, std::ios::in);
	if (newfile.is_open())
	{
		while (getline(newfile, ln)) //read each line of the file
		{

			if (ln.find("new graph") != std::string::npos)
			{

				if (started)
				{
					std::cout << "got to the printing" << std::endl;
					printAJList();			// printing operations
					printMatrix();
					BFSearch(graph[0]);		//searching with a reset in between
					resetVList();
					std::cout << "Printing elements as seen through Depth First Search" << std::endl;
					DFSearch(graph[0]);
					graph.clear();		//restarting the graph
				}
				started = true;
			}
			else if (ln.find("add vertex") != std::string::npos)
			{
				int id = std::stoi(ln.substr(11));
				Vertex *vertex = new Vertex();
				vertex->id = id;
				graph.push_back(vertex);			//make a vertex with an id of the number on the line
			}
			else if (ln.find("add edge") != std::string::npos)
			{

				int hyph = ln.find("-");

				int num1 = stoi(ln.substr((ln.find("edge") + 5), 2));					//grabbing both numbers out
				int num2 = stoi(ln.substr(hyph + 2));

				for (int i = 0; i < graph.size(); i++)				//using two different "fingers" on the vector at a time
				{
					if (graph[i]->id == num1)
					{
						for (int j = 0; j < graph.size(); j++)
						{
							if (graph[j]->id == num2)
							{
								graph[i]->neighbors.push_back(graph[j]);			//a neighbor of b,  b neighbor of a
								graph[j]->neighbors.push_back(graph[i]);
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
void GraphManager::printAJList()
{
	std::cout << "---Printing Adjacency List---" << std::endl;
	for (int i = 0; i < graph.size(); i++)
	{
		std::cout << "[" << graph[i]->id << "]";
		for (int j = 0; j < graph[i]->neighbors.size(); j++)				// list out the neighbors of each
		{
			std::cout << " " << graph[i]->neighbors[j]->id;
		}
		std::cout << std::endl;
	}
}
void GraphManager::printMatrix()
{
	int size = graph.size();
	std::cout << "about to do matrix stuff" << std::endl;
	std::vector<std::vector<char>> matrix(size, std::vector<char>(size, '.'));
	std::cout << "--Printing Matrix--" << std::endl;

	//populating
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i]->neighbors.size(); j++)
		{

			matrix[i][graph[i]->neighbors[j]->id] = '1';
		}
	}
	//printing
	std::cout << "    ";
	//table headings
	for (int n = 0; n < graph.size(); n++)
	{
		if (graph[n]->id < 10)
		{
			std::cout << graph[n]->id << "  ";
		}
		else
		{
			std::cout << graph[n]->id << " ";
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < graph.size(); i++)				// line headers
	{
		if (graph[i]->id < 10)
		{
			std::cout << " " << graph[i]->id << "| ";
		}
		else
		{
			std::cout << graph[i]->id << "| ";
		}
		//printing row by row

		for (int h = 0; h < matrix[i].size(); h++)
		{
			std::cout << matrix[i][h] << "  ";
		}
		std::cout << std::endl;
	}
}

void GraphManager::resetVList()
{
	for (int i = 0; i < graph.size(); i++)			//set everything back to unprocessed
	{
		graph[i]->processed = false;
	}
}
void GraphManager::BFSearch(Vertex *startV)
{
	std::cout << "Printing elements as seen through Breadth First Search" << std::endl;
	Queue q = Queue();
	q.enQueue(startV);
	startV->processed = true;			//start with the first vertex as passed
	while (!q.isEmpty())
	{
		Vertex *cv = q.deQueue().data;		
		std::cout << cv->id << std::endl;
		for (int i = 0; i < cv->neighbors.size(); i++)		//if the current vertex's neighbors arent processed enqueue them and mark them as processesed
		{
			if (!cv->neighbors[i]->processed)
			{
				q.enQueue(cv->neighbors[i]);
				cv->neighbors[i]->processed = true;
			}
		}
	}
	std::cout << "------------------------------" << std::endl;
}

void GraphManager::DFSearch(Vertex *startV)
{

	if (!startV->processed)		//if the start vertex isnt processed, mark it as processed after printing its id
	{
		std::cout << startV->id << std::endl;
		startV->processed = true;
	}
	for (int i = 0; i < startV->neighbors.size(); i++)	//iterate through the starting vertex's neighbors until an unprocessed one is found. then call DFSearch on it
	{
		if (!startV->neighbors[i]->processed)
		{
			DFSearch(startV->neighbors[i]);
		}
	}
}
