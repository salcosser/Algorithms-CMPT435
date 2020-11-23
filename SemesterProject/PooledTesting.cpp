
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

bool PooledTesting::test(int sPoolIndex, int iStart, int iEnd)
{
    std::cout << "------------Test set #" << ++testCounter << "---------------" << std::endl;
    std::cout << "-------- Testing Pool #" << sPoolIndex << ", " << iStart << " to " << iEnd << "--------" << std::endl;
    bool foundCase = false;

    if ((iEnd - iStart) > 1)
    {
        std::cout << " ";
        for (int i = iStart; i < iEnd; i++)
        {
            if (testPools[sPoolIndex][i] == 1)
            {
                foundCase = true;
                std::cout << "X ";
            }
            else
            {
                std::cout << "O ";
            }
        }
       
        std::cout << std::endl;
        std::cout << " 'X's denote positive cases, 'O's denote negative cases." << std::endl;
    }
    else
    {
        if (testPools[sPoolIndex][iStart] == 1)
        {
            activeCases++;
            foundCase = true;
            
            std::cout << "ALERT: a conclusive case was found. in pool #" << sPoolIndex << " index " << iStart << std::endl;
        }
    }
    std::cout << "------------"
              << "total cases after testing:" << activeCases << "------------" << std::endl;
    return foundCase;
}

void PooledTesting::runTests(int sPoolIndex, int iStart, int iEnd)
{
    int mid = (iStart + iEnd) / 2;

    bool tCaseA = test(sPoolIndex, iStart, mid);
    bool tCaseB = test(sPoolIndex, mid, iEnd);

   
    if (tCaseA && ((mid - iStart) > 1))
    {
        runTests(sPoolIndex, iStart, mid);
    }
    else
    {
        std::cout << "Pool #" << sPoolIndex << " persons " << iStart << " - " << (mid + 1) << " have been cleared." << std::endl;
    }

    if (tCaseB && ((iEnd - mid) > 1))
    {
        runTests(sPoolIndex, mid, iEnd);
    }
    else
    {
        std::cout << "Pool #" << (sPoolIndex + 1) << " persons " << (mid + 1) << " - " << iEnd << " have been cleared." << std::endl;
    }
}

void PooledTesting::testThePools(int sampleSize, double perCent)
{
    setupPools(sampleSize, perCent);
    for (int i = 0; i < testPools.size(); i++)
    {
        std::cout << "_____________________________" << std::endl;
        std::cout << "Beginning testing on pool #" << i + 1 << std::endl;
        runTests(i, 0, testPools.at(i).size());
        std::cout << "Testing for pool #" << i + 1 << " is complete." << std::endl;
        std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    }
    std::cout << "Total cases found:" << activeCases << std::endl;
    std::cout << "Total tests used:" << testCounter << std::endl;
    activeCases = 0;
    testCounter = 0;
    tPeople = 1000;
    testPools.clear();
    std::cout << "Data has been reset." << std::endl;
}