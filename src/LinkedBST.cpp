#include "LinkedBST.h"
#include <iostream>

LinkedBST::LinkedBST()
{
    root = NULL;
}

LinkedBST::~LinkedBST() {}

bool LinkedBST::isEmpty()
{
    return root == NULL;
}

void LinkedBST::add(int key, int value)
{
    root = addR(root, key, value);
}

Node *LinkedBST::addR(Node *root, int key, int value)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->value = value;

    if (root == NULL)
    {
        root = newNode;
    }
    else if (key < root->key)
    {
        root->leftChild = addR(root->leftChild, key, value);
    }
    else if (key > root->key)
    {
        root->rightChild = addR(root->rightChild, key, value);
    }
    else
    {
        std::cout << "Duplicate keys!\n";
    }
    return root;
}

bool LinkedBST::remove(int keyToDelete)
{
    return root = removeR(root, keyToDelete);
}

Node *LinkedBST::removeR(Node *root, int keyToDelete)
{
    if (root == NULL)
    {
        return root;
    }

    if (keyToDelete < root->key)
    {
        root->leftChild = removeR(root->leftChild, keyToDelete);
    }
    else if (keyToDelete > root->key)
    {
        root->rightChild = removeR(root->rightChild, keyToDelete);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            Node *temp = root->rightChild;
            delete root;
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            Node *temp = root->leftChild;
            delete root;
            return temp;
        }
        else
        {
            Node *minRight = minNode(root->rightChild);
            root->value = minRight->value;
            root->key = minRight->key;
            root->rightChild = removeR(root->rightChild, minRight->key);
        }
    }
}

Node *LinkedBST::minNode(Node *node)
{
    Node *temp = node;
    while (temp && temp->leftChild != nullptr)
    {
        temp = temp->leftChild;
    }
    return temp;
}

void LinkedBST::max(int &output)
{
    if (!isEmpty())
    {
        Node *temp = root;
        while (temp->rightChild != NULL)
        {
            temp = temp->rightChild;
        }
        output = temp->value;
    }
    else
    {
        std::cout << "Tree Empty!" << std::endl;
    }
}

void LinkedBST::min(int &output)
{
    if (!isEmpty())
    {
        Node *temp = root;
        while (temp->leftChild != NULL)
        {
            temp = temp->leftChild;
        }
        output = temp->value;
    }
    else
    {
        std::cout << "Tree Empty!" << std::endl;
    }
}

bool LinkedBST::search(int targetKey)
{
    return searchR(root, targetKey);
}

bool LinkedBST::searchR(Node *root, int targetKey)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->key == targetKey)
    {
        return true;
    }
    if (root->key > targetKey)
    {
        return searchR(root->leftChild, targetKey);
    }
    else
    {
        return searchR(root->rightChild, targetKey);
    }
}