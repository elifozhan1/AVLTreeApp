#ifndef StackNode_hpp
#define StackNode_hpp

// yigit icin dugum sinifi

class StackNode
{
public:
    int item;
    StackNode* next;

    StackNode(const int& , StackNode* );
    ~StackNode();
};

#endif