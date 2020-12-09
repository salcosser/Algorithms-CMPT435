#pragma once
#include <iostream>
#include <vector>
class PooledTesting
{
public:
    int tPeople = 0;                                                  //holds the population size
    const int poolSize = 8;                                           //holds the size of the pools as a constant
    int activeCases = 0;                                              //holds the current active cases as observed
    int testCounter = 0;                                              // holds a counter of the amount of tests used
    void setupPools(double size, double pcPos);                       //is used to initialize the pools with randomly assigned active cases
    void testThePools(int sampleSize, double perCent, bool printOut); // is used to implement the testing function  itTest()
    void itTest(int sPoolIndex, bool readOut);                        //tests the pool which it is designated to
    std::vector<std::vector<int>> testPools;                          //holds a two dimensional vector of vectors, the inner vectors being the pools
};