#ifndef Node_hpp
#define Node_hpp

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char data);
    ~Node();
};

#endif