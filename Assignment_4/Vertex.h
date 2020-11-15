#pragma once
#include <iostream>
#include <vector>
class Vertex{
    public:
    int id;     //id of the vertex
    bool processed;     //used for searching
    std::vector<Vertex*> neighbors;     //all of the one hop neighbors
};