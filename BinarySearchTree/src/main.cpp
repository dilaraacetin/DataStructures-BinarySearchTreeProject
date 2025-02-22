#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "BST.hpp"
#include "BSTList.hpp"

using namespace std;

BSTList treeList;


int main() 
{
    BST tree;
    ifstream dosya("agaclar.txt");
    if (!dosya.is_open()) 
    {
    cout << "Dosya acilamadi." << endl;
    return 1;
    }

    string satir;
    while (getline(dosya, satir)) {
        if (!satir.empty()) {
            BST* newTree= new BST();
            for (char data : satir) {
                if(data!=' ')
                newTree->insertNode(data);
            }
            treeList.addTree(newTree);
        }
    }
    dosya.close();


    while(true)
    {
        system("cls");
        treeList.view();
        char input;
        cin >> input;
        treeList.usersInput(input);
        
        
    }
    
    return 0;
}



