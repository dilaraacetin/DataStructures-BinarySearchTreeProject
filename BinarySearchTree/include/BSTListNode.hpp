#ifndef BSTListNode_hpp
#define BSTListNode_hpp
#include "BST.hpp"

class BSTListNode {
public:
    BST* tree;            
    BSTListNode* next;    

    BSTListNode(BST* tree);
    ~BSTListNode();
};

#endif