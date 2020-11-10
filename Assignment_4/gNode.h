#pragma once
#include <iostream>
#include <vector>
class gNode{
    public:
    int id;
    bool processed;
    std::vector<int> neighbors;
};