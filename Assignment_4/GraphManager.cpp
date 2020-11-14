
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
					printAJList();
					printMatrix();
					BFSearch(linkedVect[0]);
					resetVList();
					std::cout << "Printing elements as seen through Depth First Search" <<std::endl;
					DFSearch(linkedVect[0]);
					linkedVect.clear();
				}
				started = true;
			}
			else if (ln.find("add vertex") != std::string::npos)
			{
				int id = std::stoi(ln.substr(11));
				Vertex *vertex = new Vertex();
				vertex->id = id;
				linkedVect.push_back(vertex);
			}
			else if (ln.find("add edge") != std::string::npos)
			{

				int hyph = ln.find("-");

				int num1 = stoi(ln.substr((ln.find("edge") + 5), 2));
				int num2 = stoi(ln.substr(hyph + 2));

				for (int i = 0; i < linkedVect.size(); i++)
				{
					if (linkedVect[i]->id == num1)
					{
						for (int j = 0; j < linkedVect.size(); j++)
						{
							if (linkedVect[j]->id == num2)
							{
								linkedVect[i]->neighbors.push_back(linkedVect[j]);
								linkedVect[j]->neighbors.push_back(linkedVect[i]);
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
	for (int i = 0; i < linkedVect.size(); i++)
	{
		std::cout << "[" << linkedVect[i]->id << "]";
		for (int j = 0; j < linkedVect[i]->neighbors.size(); j++)
		{
			std::cout << " " << linkedVect[i]->neighbors[j]->id;
		}
		std::cout << std::endl;
	}
}
void GraphManager::printMatrix()
{
	int size = linkedVect.size();
	std::cout << "about to do matrix stuff" << std::endl;
	std::vector<std::vector<char>> matrix(size, std::vector<char>(size, '.'));
	std::cout << "--Printing Matrix--" << std::endl;

	//populating
	for (int i = 0; i < linkedVect.size(); i++)
	{
		for (int j = 0; j < linkedVect[i]->neighbors.size(); j++)
		{

			matrix[i][linkedVect[i]->neighbors[j]->id] = '1';
		}
	}
	//printing
	std::cout << "    ";
	//table headings
	for (int n = 0; n < linkedVect.size(); n++)
	{
		if (linkedVect[n]->id < 10)
		{
			std::cout << linkedVect[n]->id << "  ";
		}
		else
		{
			std::cout << linkedVect[n]->id << " ";
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < linkedVect.size(); i++)
	{
		if (linkedVect[i]->id < 10)
		{
			std::cout << " " << linkedVect[i]->id << "| ";
		}
		else
		{
			std::cout << linkedVect[i]->id << "| ";
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
	for (int i = 0; i < linkedVect.size(); i++)
	{
		linkedVect[i]->processed = false;
	}
}
void GraphManager::BFSearch(Vertex *startV)
{	
	std::cout << "Printing elements as seen through Breadth First Search" <<std::endl;
	Queue q = Queue();
	q.enQueue(startV);
	startV->processed = true;
	while (!q.isEmpty())
	{
		Vertex *cv = q.deQueue().data;
		std::cout << cv->id << std::endl;
		for (int i = 0; i < cv->neighbors.size(); i++)
		{
			if (!cv->neighbors[i]->processed)
			{
				q.enQueue(cv->neighbors[i]);
				cv->neighbors[i]->processed = true;
			}
		}
	}
	std::cout << "------------------------------"<< std::endl;
}

void GraphManager::DFSearch(Vertex *startV)
{
	
	if (!startV->processed)
	{
		std::cout << startV->id << std::endl;
		startV->processed = true;
	}
	for (int i = 0; i < startV->neighbors.size(); i++)
	{
		if (!startV->neighbors[i]->processed)
		{
			DFSearch(startV->neighbors[i]);
		}
	}
}
