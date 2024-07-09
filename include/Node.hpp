#ifndef Stack_hpp
#define Stack_hpp

// avl agaci icin dugum sinifi

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(const int &);
    ~Node();
};

#endif