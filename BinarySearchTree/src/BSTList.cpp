#include "BSTList.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>

BSTList::BSTList() : head(nullptr), treeNum(0),index(0), lowerValue(0), upperValue(1) {}

BSTList::~BSTList() {
    while (head != nullptr) {
        BSTListNode* temp = head;
        head = head->next;
        delete temp->tree;   
        delete temp;         
    }
}

void BSTList::addTree(BST* tree) {
    BSTListNode* newNode = new BSTListNode(tree);
    if (head == nullptr) {
        head = newNode;
    } else {
        BSTListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    treeNum++;
}

void BSTList::usersInput(char input)
{
    if (head == nullptr) {
        cout << "Tum agaclar silindi." << endl;
        return;
    }
    if(input=='a'||input=='A')
    {
        --index;
        if(index<0)
        index=0;
    }
    else if(input=='d'||input=='D')
    {
        ++index;
        if(index>treeNum-1)
        index--;
    } 
   else if(input=='s'||input=='S')
    {
        
        deleteTree(index);
        system("cls");
        index--;
        if(index<0)
        {
            index=0;
        }  
        if(treeNum==0)
        {
            head=nullptr;
        }
    }
    else if(input=='w'||input=='W')
    {
        BSTListNode* temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        temp->tree->mirrortree();
    }
    else
    {
        cout<<"Lutfen gecerli bir secim yapiniz."<<endl;
        getchar();
        getchar();
    }
}

void BSTList :: deleteTree(int index)
{
    if(index<0|| index>= treeNum||treeNum==0)
    {
        cout<<"Gecersiz agac secimi."<<endl;
        return;
    }
    BSTListNode* temp=head;
    BSTListNode* previous=nullptr;
    for (int i=0; i<index;i++)
    {
        previous=temp;
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Agac bulunamadi"<<endl;
        return;
    }
    if (previous == nullptr) {
        head = temp->next;
    } else {
        previous->next = temp->next;
    }

    
    delete temp->tree;
    delete temp;       
    treeNum--;  
} 

void BSTList:: view()
{
    BSTListNode* temp= head;

    if(head!=nullptr)
    {
        if (lowerValue==0 && index/10==lowerValue)
    {
        temp=head;
        
    }
    else
    {
        if(index/10==upperValue)
        {
            upperValue++;
            lowerValue++;
        }
        else if(index/10<lowerValue)
        {
            upperValue--;
            lowerValue--;
        }
        for (int i = 0; i < lowerValue * 10 ; i++) 
        {
            temp = temp->next;
        }

    }
    
    print(temp);
    cout<<endl;
    printNode(temp);
    cout<<endl;
    print(temp);
    cout<<endl;
    printSumNodes(temp);
    cout<<endl;
    print(temp);
    cout<<endl;
    printNextnode(temp);
    cout<<endl;
    print(temp);
    cout<<endl;

    
    for(int i=0;i<=(index%10)*12+(index%10)-1;i++)
    {
        cout<<" ";
    }
    cout<<"^^^^^^^^^^"<<endl;
    for(int i=0;i<=(index%10)*12+(index%10)-1;i++)
    {
        cout<<" ";
    }
    cout<<"||||||||||"<<endl;
    temp=head;
    for(int i=0; i<index;i++)
    {
        temp=temp->next;
    }
    temp->tree->printTree();
    cout<<endl;
    }
    else
    {
        cout<<"Tum agaclar silindi."<<endl;
    }
}

void BSTList:: print(BSTListNode* Node)
{
    int space=3;
     for (int i = 0; i < 10 && Node != nullptr; i++)
    {
        if(Node!=nullptr)
        {
        cout << "..........";
        for(int i=0;i<space;i++)
        {cout<<" ";}
        Node = Node->next;
        }
        else 
            break;
    }
}

void BSTList::printNode(BSTListNode* Node)
{
    int space = 3; 
    for (int i = lowerValue * 10; i < upperValue * 10 && Node != nullptr; i++) 
    {   
        cout << ".    ";
        uintptr_t address = reinterpret_cast<uintptr_t>(Node);
        cout << setfill('0') << setw(4) << (address % 10000); 
        cout << ".";
        for (int j = 0; j < space; j++) {
            cout << " ";
        }

        Node = Node->next; 
    }
}

void BSTList::printNextnode(BSTListNode* Node) 
{
    int space = 3; 
    for (int i = lowerValue * 10; i < upperValue * 10 && Node != nullptr; i++) 
    {   
        cout << ".    ";
        uintptr_t address = reinterpret_cast<uintptr_t>(Node->next);
        cout << setfill('0') << setw(4) << (address % 10000); 
        cout << ".";
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        
        Node = Node->next; 
    }
}

void BSTList::printSumNodes(BSTListNode* Node)
{
    int space=3;
    for (int i = lowerValue*10; i < upperValue*10 && Node != nullptr; i++) 
    {   
        int sum= Node->tree->calculateSum();
        cout << ".    ";
        cout << setfill('0') << setw(4) 
         << sum << dec; 
        cout << ".";
        for(int i=0;i<space;i++)
        {cout<<" ";}
        Node = Node->next;
    }
}

   

  

