#include <iostream>
#include <stdio.h>



using namespace std;


#include "ArrayBST.cpp"

int main(int argc, char const *argv[])
{
    ArrayBinarySearchTree *bst= new ArrayBinarySearchTree();
    bst->add(5,5);

    bst->search(5);

    bst->remove(5);

    bst->isEmpty();


    return 0;
}
