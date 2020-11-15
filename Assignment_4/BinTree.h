#pragma once
#include <string>
#include <iostream>
#include "BinNode.h"

class BinTree{
    public:
    BinNode static search(BinNode * root, std::string key, int &count);
    void  insert(std::string key);
    BinNode * root;
    void pullBatch(std::string items[], int len);
};