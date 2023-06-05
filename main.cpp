#include <iostream>
#include <stdio.h>

using namespace std;

#include "ArrayBST.cpp"
#include "LinkedBST.h"

int main(int argc, char const *argv[])
{
    cout << "ArrayBST implementation\n";

    ArrayBinarySearchTree *bst = new ArrayBinarySearchTree();

    bst->add(5, 5);

    bst->search(5);

    bst->remove(5);

    bst->isEmpty();

    cout << "LinkedBST implementation\n";

    LinkedBST l;

    cout << "Is the BST empty? " << (l.isEmpty() ? "Yes" : "No") << endl;

    cout << "adding values into the tree: \n";
    l.add(50, 5);
    l.add(30, 3);
    l.add(40, 4);
    l.add(20, 2);
    cout << "Is the BST empty? " << (l.isEmpty() ? "Yes" : "No") << endl;

    cout << "Search 20: " << (l.search(20) ? "Found" : "Not Found") << endl;

    cout << "Removing 20" << endl;
    l.remove(20);

    cout << "Search 20: " << (l.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}
