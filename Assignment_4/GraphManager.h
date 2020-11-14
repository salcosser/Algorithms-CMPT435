#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vertex.h"
class GraphManager{
    public:
    static const int MAX_V = 100;
    std::vector<Vertex*> linkedVect;
    void Overlord(std::string fileName);
    void printAJList();
    void printMatrix();
    void BFSearch(Vertex* startV);
    void DFSearch(Vertex* startV);
    void resetVList();
    
};