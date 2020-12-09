
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <random>
#include <vector>
#include "PooledTesting.h"

void PooledTesting::setupPools(double size, double pcPos)
{

    tPeople = size;
    std::vector<int> population(tPeople, 0);                  //holds the whole population
    int numPos = (int)(static_cast<double>(tPeople) * pcPos); //number of positive cases needed

    std::vector<int> indexes;
    int chosen = 0;
    while (chosen < numPos) // get the right amount of positive numbers for indexes
    {

        std::random_device dev; //making the random number
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, (tPeople - 1));
        int attempt = dist6(rng);
        if (std::find(indexes.begin(), indexes.end(), attempt) != indexes.end()) //if the number hasnt been chosen, add it to the list. Otherwise skip
        {
            continue;
        }
        else
        {

            indexes.push_back(attempt);
            population[attempt] = 1;
            chosen++;
        }
    }

    int remainder = tPeople % poolSize; //keep track of remainder people

    int pools = (tPeople - remainder) / poolSize; //find the number of needed pools

    for (int i = 0; i < pools; i++) //setup the pools with their people
    {
        std::vector<int> pool;
        for (int j = 0; j < poolSize; j++)
        {
            int subInd = (i * poolSize) + j; //find the right index by taking the current index plus the already processed indexes
            pool.push_back(population[subInd]);
        }
        testPools.push_back(pool);
    }
    if (remainder > 0) //complete the same process for the remainders, in one final pool
    {
        int processedCounter = pools * poolSize; //start the index after the last processed index
        std::vector<int> remVect;
        for (int x = processedCounter - 1; x < tPeople; x++)
        {
            remVect.push_back(population[x]);
        }
        testPools.push_back(remVect);
    }
    std::cout << testPools.size() << " pools have been set up." << std::endl;
}

void PooledTesting::itTest(int sPoolIndex, bool readOut)
{
    int poolCases = 0;
    int poolTests = 0;
    //full test
    bool initPos = false;
    testCounter++;
    poolTests++;
    for (int i = 0; i < poolSize; i++)
    { //initial screening

        if (testPools[sPoolIndex][i] == 1)
        {
            initPos = true;
        }
    }
    if (initPos)
    { //testing both parts in groups of 4
        bool s1 = false;
        bool s2 = false;
        testCounter++;
        poolTests++;
        for (int j = 0; j < 4; j++)
        {

            if (testPools[sPoolIndex][j] == 1)
            {
                s1 = true;
            }
        }
        testCounter++;
        poolTests++;
        for (int k = 4; k < poolSize; k++)
        {

            if (testPools[sPoolIndex][k] == 1)
            {
                s2 = true;
            }
        }
        if (s1)
        { // single tests
            for (int n = 0; n < 4; n++)
            {
                testCounter++;
                poolTests++;
                if (testPools[sPoolIndex][n] == 1)
                {
                    activeCases++;
                    poolCases++;
                    if (readOut)
                    {
                        std::cout << "Positive case found in pool #" << sPoolIndex << " for person " << n << "." << std::endl;
                    }
                }
            }
        }
        if (s2)
        {
            for (int m = 4; m < poolSize; m++)
            {
                testCounter++;
                poolTests++;
                if (testPools[sPoolIndex][m] == 1)
                {
                    activeCases++;
                    poolCases++;
                    if (readOut)
                    {
                        std::cout << "Positive case found in pool #" << sPoolIndex << " for person " << m << "." << std::endl;
                    }
                }
            }
        }
        if (readOut)
        {
            std::cout << "POOL #" << sPoolIndex << ":Tests used:" << poolTests << std::endl;
            std::cout << "POOL #" << sPoolIndex << ":Cases found:" << poolCases << std::endl;
        }
    }
    else
    {
        if (readOut)
        {
            std::cout << "Pool #" << sPoolIndex << " came back negative." << std::endl;
            std::cout << "POOL #" << sPoolIndex << ":Tests used:" << poolTests << std::endl;
            std::cout << "POOL #" << sPoolIndex << ":Cases found:" << poolCases << std::endl;
        }
    }
}
void PooledTesting::testThePools(int sampleSize, double perCent, bool readOut)
{
    setupPools(sampleSize, perCent);           //run the setup
    for (int i = 0; i < testPools.size(); i++) //run the pool test on each pool
    {

        itTest(i, readOut);
        if (readOut)
        {
            std::cout << "_____________________________" << std::endl;
            std::cout << "Beginning testing on pool #" << i + 1 << std::endl;

            std::cout << "Testing for pool #" << i + 1 << " is complete." << std::endl;
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
        }
    }
    std::cout << "Total cases found:" << activeCases << std::endl; //print out the resulting data
    std::cout << "Observed infection percentage:" << std::to_string(((double)activeCases / (double)sampleSize) * 100.0) << "%" << std::endl;

    std::cout << "Total tests used:" << testCounter << std::endl;
    activeCases = 0; //reset all data
    testCounter = 0;
    tPeople = 1000;
    testPools.clear();
    std::cout << "Data has been reset." << std::endl;
}