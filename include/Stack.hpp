#ifndef STACK_hpp
#define STACK_hpp

#include "StackNode.hpp"

// yigit sinifi (avl agaclarinin yaprak degerlerini tutmak icin var)

class Stack
{
public:
    StackNode *topOfStack;
    StackNode *firstStack;

    Stack();
    bool isEmpty() const;
    void push(const int &item);
    void pop();
    void fill();
    const int &top() const;
    void makeEmpty();
    ~Stack();
};

#endif