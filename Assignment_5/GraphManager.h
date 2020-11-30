#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
using namespace std;
class GraphManager{
    public:
    vector<Vertex*> graph;
    vector<Edge *> edges;
    void fileReader(string fileName);

    
};