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
    void relax(Edge * edge, Vertex * from, Vertex * dest);
     bool Bellman();
     void bellmanOut(Vertex * source);
     void printPath(Vertex * source, Vertex * dest);
};