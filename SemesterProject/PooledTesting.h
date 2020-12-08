#pragma once
#include <iostream>
#include <vector>
class PooledTesting
{
public:
    int tPeople = 1000;
    int poolSize = 8;
    int activeCases = 0;
    int testCounter = 0;
    void setupPools(double size, double pcPos);
    void testThePools(int sampleSize, double perCent, bool printOut);
    void itTest(int sPoolIndex, bool readOut);
    std::vector<std::vector<int>> testPools;
};