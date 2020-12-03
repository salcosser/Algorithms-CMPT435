#pragma once
#include <iostream>
#include "Vertex.h"
class Vertex;
class Edge
{
public:
    int weight;         //weight of the edge
    Vertex *dest;       //points to where the edge goes
    Vertex *from;       //points to where the edge is from
};