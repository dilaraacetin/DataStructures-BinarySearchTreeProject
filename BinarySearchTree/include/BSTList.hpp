#ifndef BSTList_hpp
#define BSTList_hpp
#include "BSTListNode.hpp"

class BSTList {
public:
    BSTListNode* head;
    int treeNum;
    int index;
    int lowerValue;
    int upperValue;

    BSTList();
    ~BSTList();            
    void addTree(BST* tree);  
    void deleteTree(int index);
    void usersInput(char input);
    void view();
    void print(BSTListNode* Node);
    void printNode(BSTListNode* Node);
    void printNextnode(BSTListNode* Node);
    void printSumNodes(BSTListNode* Node);
};
#endif