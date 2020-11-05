#pragma Once
#include <string>
class BinNode
{ // defining class for the node that has the pointer and the data
public:
	std::string key; // stores data for the node
	BinNode* left = nullptr;		  // stores pointer for the node
    BinNode* right = nullptr;
	BinNode* parent = nullptr;
};
