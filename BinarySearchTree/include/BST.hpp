#ifndef BST_hpp
#define BST_hpp


#include "Node.hpp"
#include <queue>
#include <cmath>
using namespace std;

const int MAX_ROWS = 20;    
const int MAX_COLUMNS = 100; 


class BST {
public:

    BST();
    ~BST();
    Node* createNode(char data);
    void insertNode(char data);
    void inorderTraversal(Node* root);
    void destroyTree(Node* node);
    Node* searchNode(Node* root, int key);
    Node* deleteNodeByData(Node* root, char data);
    void mirrortree();
    int calculateSum();
    void printTree();
    void boslukYaz(int sayi);
    void kendiPrint();
    int height();

private:
    int height(Node*node);
    Node* insertNode(Node* root, char data);
    void initializeOutput(char output[MAX_ROWS][MAX_COLUMNS]);
    void printTreeHelper(Node* node, int left, int right, int level, char output[MAX_ROWS][MAX_COLUMNS]);
    void mirrortree(Node* root);
    int calculateTotalSum(Node*node, bool isLeftChild);
    Node* minValueNode(Node* node);
    Node* root;
};

#endif