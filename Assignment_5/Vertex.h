#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"
class Edge;
class Vertex
{
public:
    int id;
    int distance;
    Vertex *prev;
};
