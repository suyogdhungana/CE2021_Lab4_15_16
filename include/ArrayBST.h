#ifndef arrayBST_h
#define arrayBST_h

#include <iostream>
#include "AbstractBST.h"
using namespace std;



const int MAX_SIZE = 100; // Maximum size of the array

class ArrayBinarySearchTree {
private:
    struct Arraynode {
        int key;
        int value;
        Arraynode(int k, int v) : key(k), value(v) {}
    };

    Arraynode* nodes[MAX_SIZE]; // Array to store the nodes of the tree

public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();

    bool isEmpty();
    void add(int key, int value);
    void min(int& output);
    void max(int& output);
    bool remove(int key);
    bool search(int targetkey);
};

#endif