#include <iostream>
#include "ArrayBST.h"
using namespace std;

ArrayBinarySearchTree::ArrayBinarySearchTree()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        nodes[i] = nullptr;
    }
}
ArrayBinarySearchTree::~ArrayBinarySearchTree() {}

bool ArrayBinarySearchTree::isEmpty()
{
    if (nodes[0] == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ArrayBinarySearchTree::add(int key, int value)
{
    Arraynode *newNode = new Arraynode(key, value);

    for (int i = 1; i < MAX_SIZE;)
    {
        Arraynode *node = this->nodes[i];
        if (node == NULL)
        {
            this->nodes[i] = newNode;
            break;
        }
        else if (node->key < key)
        {
            i = 2 * i + 1;
        }
        else if (node->key > key)
        {
            i = 2 * i;
        }
    }

    cout << "Node added" << endl;
}
void ArrayBinarySearchTree::min(int &output)
{
    if (isEmpty())
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        int i = 1;
        while (i <= MAX_SIZE)
        {
            if (nodes[2 * i] == NULL)
            {
                break;
            }

            else
            {
                i = 2 * i;
            }
        }
        if (i < MAX_SIZE)
        {
            output = nodes[i]->key;
        }
    }
}

void ArrayBinarySearchTree ::max(int &output)
{
    if (isEmpty())
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        int i = 1;
        while (i < MAX_SIZE)
        {
            if (nodes[2 * i] == NULL)
            {
                break;
            }
            else
            {
                i = 2 * i + 1;
            }
        }
        if (i < MAX_SIZE)
        {
            output = nodes[i]->key;
        }
    }
}
bool ArrayBinarySearchTree::remove(int key)
{
    int i = 1;
    while (i < MAX_SIZE)
    {
        Arraynode *node = this->nodes[i];
        if (node == NULL)
        {
            return false;
        }
        if (node->key == key)
        {
            if (nodes[2 * i] == NULL && nodes[2 * i + 1] == NULL)
            {
                nodes[i] = NULL;
                return true;
            }
            else if (nodes[2 * i] == NULL)
            {
                nodes[i] = nodes[2 * i + 1];
                nodes[2 * i + 1] = NULL;
                return true;
            }
            else if (nodes[2 * i + 1] == NULL)
            {
                nodes[i] = nodes[2 * i];
                nodes[2 * i] = NULL;
                return true;
            }
            else
            {
                int min;
                min = nodes[2 * i + 1]->key;
                remove(min);
                nodes[i]->key = min;
                nodes[2 * i + 1] = nullptr;

                return true;
            }
        }
        else if (node->key < key)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
        cout << "key not found    ";
    }
}
bool ArrayBinarySearchTree::search(int targetkey)
{
    int i = 1;
    while (i < MAX_SIZE)
    {
        Arraynode *node = this->nodes[i];
        if (node == NULL)
        {
            return false;
        }
        if (node->key == targetkey)
        {
            cout << "key found" << endl;
            return true;
        }
        else if (node->key < targetkey)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
    }
    cout << "key not found";
    return false;
}
