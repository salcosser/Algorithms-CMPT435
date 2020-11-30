#pragma once
#include <iostream>
#include "Vertex.h"
class Vertex;
class Edge
{
public:
    int weight;
    Vertex *dest;
    Vertex *from;
};