#include "BSTListNode.hpp"

using namespace std;

BSTListNode::BSTListNode(BST* tree) : tree(tree), next(nullptr) {}
BSTListNode::~BSTListNode(){}