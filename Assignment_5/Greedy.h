#pragma once
#include <string>
#include <vector>
#include "Spice.h"
using namespace std;
class Greedy
{
public:
    void setupSpices(std::string fileName);
    void greedyAlgo(int capacity);
    vector<Spice *> spices;
};
