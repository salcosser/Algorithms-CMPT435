#include "BinTree.h"
//#include "BinNode.h"
#include <iostream>
#include <string>

BinNode BinTree::search(BinNode * rNode, std::string key, int &count){
    if(rNode==nullptr || key == rNode->key){
       count++;
       return *rNode;
    }else if(key < rNode->key){
         count++;
        return search(rNode->left, key, count);
    }else{
        count++;
        return search(rNode->right, key, count);   
    }
}



void BinTree::insert(std::string key){
   BinNode * node = new BinNode();
    node->key = key;
    BinNode * ancestorNode = nullptr;
    BinNode * parent = root;
    while(parent != nullptr){
        ancestorNode = parent;
        if(node->key < parent->key){
            parent = parent->left;
        }else{
            parent = parent->right;
        }
       

    }
     node->parent = ancestorNode;
     if(ancestorNode == nullptr){
         root = node;
     }else if(node->key < ancestorNode->key){
         ancestorNode->left = node;
       //  std::cout  << "placed node left"<< std::endl;
     }else{
         ancestorNode->right = node;
         // std::cout  << "placed node right"<< std::endl;
     }

}


void BinTree::pullBatch(std::string items[], int len){

	int tCount = 0;
	for(int i = 0; i < len; i++){
		int count = 0;
		auto  res = search(root, items[i], count);
		std::cout  << " was found after " << count << " comparisons." << std::endl;
		tCount+=count;
	}
    std::cout << "Total comparions to find all items: " << tCount << std::endl;
    int avg = tCount / len;
    std::cout<< "Average comparisons to reach each item: " << avg << std::endl;
}