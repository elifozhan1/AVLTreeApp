#ifndef LinkedListNode_hpp
#define LinkedListNode_hpp

#include "AVL.hpp"

// bagli liste icin dugum sinifi

class LinkedListNode
{
public:
    AVL *avlTree;
    Stack *stack;
    int orderOfTree;
    LinkedListNode *next;

    LinkedListNode(AVL *, LinkedListNode *);
    ~LinkedListNode();
};

#endif