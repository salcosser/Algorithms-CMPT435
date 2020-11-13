#pragma once
#include <iostream>
#include <vector>
class Vertex{
    public:
    int id;
    bool processed;
    std::vector<Vertex*> neighbors;
};