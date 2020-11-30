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
    vector<Edge *> weightMatrix;
    void fileReader(string fileName);
    void init(Vertex * source);
    void relax(Edge * edge);
     bool Bellman();
     void bellmanOut();
};