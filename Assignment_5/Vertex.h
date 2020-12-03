#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"
class Edge;
class Vertex
{
public:
    int id;         //id of the vertex
    int distance;   //distance from the source
    Vertex *prev;   //points to the previous vertex
};
