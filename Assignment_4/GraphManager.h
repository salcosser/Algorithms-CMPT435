#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
class GraphManager{
    public:
    std::vector<Vertex*> graph;
    void Overlord(std::string fileName);
    void printAJList();
    void printMatrix();
    void BFSearch(Vertex* startV);
    void DFSearch(Vertex* startV);
    void resetVList();
    
};