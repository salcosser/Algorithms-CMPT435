
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
    std::vector<int> population(tPeople, 0);
    int numPos = (int)(static_cast<double>(tPeople) * pcPos);

    std::vector<int> indexes;
    int chosen = 0;
    while (chosen < numPos)
    {

        std::random_device dev; //making the random number
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, (tPeople - 1));
        int attempt = dist6(rng);
        if (std::find(indexes.begin(), indexes.end(), attempt) != indexes.end())
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

    int remainder = tPeople % poolSize;

    int pools = (tPeople - remainder) / poolSize;

    for (int i = 0; i < pools; i++)
    {
        std::vector<int> pool;
        for (int j = 0; j < poolSize; j++)
        {
            int subInd = (i * poolSize) + j;
            pool.push_back(population[subInd]);
        }
        testPools.push_back(pool);
    }
    if (remainder > 0)
    {
        int processedCounter = pools * poolSize;
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
            break;
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
                break;
            }
        }
        testCounter++;
        poolTests++;
        for (int k = 4; k < poolSize; k++)
        {

            if (testPools[sPoolIndex][k] == 1)
            {
                s2 = true;
                break;
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
    setupPools(sampleSize, perCent);
    for (int i = 0; i < testPools.size(); i++)
    {
        //runTests(i, 0, testPools.at(i).size(), readOut);
        itTest(i, readOut);
        if (readOut)
        {
            std::cout << "_____________________________" << std::endl;
            std::cout << "Beginning testing on pool #" << i + 1 << std::endl;

            std::cout << "Testing for pool #" << i + 1 << " is complete." << std::endl;
            std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
        }
    }
    std::cout << "Total cases found:" << activeCases << std::endl;
    std::cout << "Observed infection percentage:" <<std::to_string(((double)activeCases / (double)sampleSize) * 100) << "%" << std::endl;
    
    std::cout << "Total tests used:" << testCounter << std::endl;
    activeCases = 0;
    testCounter = 0;
    tPeople = 1000;
    testPools.clear();
    std::cout << "Data has been reset." << std::endl;
}