#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "LinkedListNode.hpp"

// bagli liste sinifi

class LinkedList
{
public:
    LinkedListNode* head;
    int orderOfTree;

    LinkedList();
    void addAVL(AVL* );
    AVL* getHeadAVL();
    LinkedListNode* getHead() const;
    void clear();
    ~LinkedList();
};

#endif