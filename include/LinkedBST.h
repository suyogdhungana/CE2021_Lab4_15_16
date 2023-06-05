#ifndef LinkedBST_H
#define LinkedBST_H

#include "AbstractBST.h"
#include <iostream>

class Node
{
public:
    int key;
    int value;

    Node *leftChild;
    Node *rightChild;

    Node()
    {
        leftChild = NULL;
        rightChild = NULL;
    }
};

class LinkedBST : public AbstractBST
{

public:
    LinkedBST();
    ~LinkedBST();

    bool isEmpty();
    void add(int key, int value);
    void max(int &output);
    void min(int &output);

    bool remove(int keyToDelete);
    bool search(int targetKey);

private:
    Node *root;
    Node *addR(Node *root, int key, int value);
    Node *removeR(Node *root, int keyToDelete);
    Node *minNode(Node *node);
    bool searchR(Node *root, int key);
};

#endif