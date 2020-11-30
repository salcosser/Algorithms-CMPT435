#pragma once
#include <iostream>
#include <vector>


class Edge{
    public:
    Vertex * dest;
    int weight;
};

class Vertex{
    public:
    int id;     //id of the vertex
    std::vector<Edge *>edges;
   // bool processed;     //used for searching
    //std::vector<Vertex*> neighbors;     //all of the one hop neighbors
};


