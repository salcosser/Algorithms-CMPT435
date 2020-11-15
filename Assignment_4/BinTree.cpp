#include "BinTree.h"

#include <iostream>
#include <string>

BinNode BinTree::search(BinNode *rNode, std::string key, int &count)
{
    if (rNode == nullptr || key == rNode->key)  //if rNode is nullptr or rNode's key is the actual key, return rNode
    {
        count++;
        return *rNode;
    }
    else if (key < rNode->key)  // if key is smaller run the search starting from left
    {
        count++;
        return search(rNode->left, key, count);
    }
    else                   //same thing as above but start from right
    {
        count++;
        return search(rNode->right, key, count);
    }
}

void BinTree::insert(std::string key)
{
    BinNode *node = new BinNode();
    node->key = key;
    BinNode *ancestorNode = nullptr;    //trailing pointer
    BinNode *parent = root;             //used to search
    while (parent != nullptr)           //based on the node being searhed for, find an open place in the BST
    {  
        ancestorNode = parent;          //keep a record of where you are
        if (node->key < parent->key)
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
    }
    node->parent = ancestorNode;            //use record to define parent
    if (ancestorNode == nullptr)            
    {
        root = node;
    }
    else if (node->key < ancestorNode->key)     //update the trailing pointer
    {
        ancestorNode->left = node;
        //  std::cout  << "placed node left"<< std::endl;
    }
    else
    {
        ancestorNode->right = node;
        // std::cout  << "placed node right"<< std::endl;
    }
}

void BinTree::pullBatch(std::string items[], int len)
{

    int tCount = 0;
    for (int i = 0; i < len; i++)       //run search for every one of the items
    {
        int count = 0;
        auto res = search(root, items[i], count);
        std::cout << "Item "<< i+1 << " was found after " << count << " comparisons." << std::endl;
        tCount += count;
    }
    std::cout << "Total comparions to find all items: " << tCount << std::endl;
    int avg = tCount / len;                                                                  //find and display the average
    std::cout << "Average comparisons to reach each item: " << avg << std::endl;
}