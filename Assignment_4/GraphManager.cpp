
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include "GraphManager.h"
#include "Vertex.h"

void GraphManager::Overlord(std::string fileName)
{

	std::fstream newfile;

	std::string ln;
	int count = 0;

	newfile.open(fileName, std::ios::in);
	if (newfile.is_open())
	{
		while (getline(newfile, ln)) //read each line of the file
		{

			if (ln.find("new graph") != std::string::npos)
			{	
				linkedVect.clear();

				// do one of these for each line, and process thusly
				// begin the next graph

				// if it sees theres nothing in the vector, just continue
				//print stuff out, and display stuff, run the searches
				//clear vector list and print new list
			}
			else if (ln.find("add vertex") != std::string::npos)
			{
				int id = std::stoi(ln.substr(11));
				Vertex *vertex = new Vertex();
				vertex->id = id;
				linkedVect.push_back(*vertex);
				std::cout << "vertex made" << std::endl;
			}
			else if (ln.find("add edge") != std::string::npos)
			{ 
				std::string s = "add edge 1 - 11";
				int hyph = s.find("-");

				int num1 = stoi(s.substr((s.find("edge") + 5), 2));
				int num2 = stoi(s.substr(hyph + 2));
				
				for(int i = 0; i< linkedVect.size(); i++){
					if(linkedVect[i].id == num1){
						linkedVect[i].neighbors.push_back(num2);
					}else if(linkedVect[i].id == num2){
						linkedVect[i].neighbors.push_back(num1);
					}
				}
				std::cout << "edge made" << std::endl;
			}
		
			
		}
	}
	newfile.close();

	return;
};
