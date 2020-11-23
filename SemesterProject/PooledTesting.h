#pragma once
#include <iostream>
#include <vector>
class PooledTesting{
    public:
    int tPeople = 1000;
    int poolSize = 8;
    int activeCases = 0;
    int testCounter = 0;
    void runTests(int sPoolIndex, int iStart, int iEnd);
    void setupPools(double size, double pcPos);
    bool test(int sPoolIndex, int iStart, int iEnd);
    void testThePools(int sampleSize,  double perCent);
    std::vector<std::vector<int>> testPools;

};