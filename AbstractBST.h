#ifndef AbstractBST_H
#define AbstractBST_H

class AbstractBST
{
public:
    virtual bool isEmpty() = 0;
    virtual void add(int key, int value) = 0;
    virtual void max(int &output) = 0;
    virtual void min(int &output) = 0;

    virtual bool remove(int key) = 0;
    virtual bool search(int key) = 0;
};

#endif