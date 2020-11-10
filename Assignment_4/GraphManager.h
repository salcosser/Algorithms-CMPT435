#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "gNode.h"
class GraphManager{
    public:
    static const int MAX_V = 100;
    std::vector<gNode> linkedVect;
    void Overlord(std::string fileName);
    
    
};