#include "BST.hpp"
#include <iomanip>
#include <cmath>

BST::BST() 
{
    root = nullptr;
}

BST::~BST()
{
    destroyTree(root);
}

void BST::destroyTree(Node* node)
{
    if(node==nullptr)
    return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

Node* BST::deleteNodeByData(Node* root, char data) {
    if (root == nullptr) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNodeByData(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNodeByData(root->right, data);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNodeByData(root->right, temp->data);
    }
    return root;
}

void BST::insertNode(char data) {
    root = insertNode(root, data);
}

Node* BST::insertNode(Node* root, char data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void BST::inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

Node* BST::searchNode(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return searchNode(root->right, key);
    }
    return searchNode(root->left, key);
}

Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

int BST::calculateSum()
{
     return calculateTotalSum(root, false);
}

int BST::calculateTotalSum(Node* node, bool isLeftChild = false) 
{
    if (node == nullptr) return 0;

    int leftSum = calculateTotalSum(node->left, true);
    int rightSum = calculateTotalSum(node->right, false);
    int currentValue = isLeftChild ? 2 * node->data : node->data;

    return currentValue + leftSum + rightSum;
}

void BST::printTree() {
    char output[MAX_ROWS][MAX_COLUMNS];
    initializeOutput(output); 

    int width = MAX_COLUMNS; 
    printTreeHelper(root, 0, width - 1, 0, output);

    
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < width; j++) {
            cout << output[i][j];
        }
        cout << endl;
    }
}

void BST:: printTreeHelper(Node* node, int left, int right, int level, char output[MAX_ROWS][MAX_COLUMNS]) {
    if (node == nullptr || level >= MAX_ROWS) return;

    int mid = left + (right - left) / 2;
    output[level][mid] = node->data; 

    if (node->left) {
        output[level + 1][mid - 1] = '/';
        printTreeHelper(node->left, left, mid - 1, level + 2, output);
    }

    if (node->right) {
        output[level + 1][mid + 1] = '\\';
        printTreeHelper(node->right, mid + 1, right, level + 2, output);
    }
}

void BST:: initializeOutput(char output[MAX_ROWS][MAX_COLUMNS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            output[i][j] = ' ';
        }
    }
}

void mirrorTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void BST::mirrortree()
{
    mirrorTree(root);
}

void BST::kendiPrint()
{
    int yukseklik=height();
    while(yukseklik!=0)
    {
        boslukYaz(2^yukseklik);
        cout<<1;
        boslukYaz(2^yukseklik);
        cout<<endl;
        yukseklik--;
    }
    
}

void BST::boslukYaz(int sayi)
{
    for(int i=0;i<sayi;i++)
    {
        cout<<" ";

    }
    
}

int BST::height(Node* node) 
{
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return max(leftHeight, rightHeight) + 1;
}



int BST::height() 
{
    return height(root);
}
