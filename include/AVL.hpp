#ifndef AVL_hpp
#define AVL_hpp
#include <iostream>
#include "Node.hpp"
#include "Stack.hpp"

using namespace std;

// AVL agaci icin hazirlanmis sinif (icerdigi degiskenler e üye fonksiyonlar)

class AVL
{
public:
    Node *root; // kok dugum
    int sumOfNodes; // dugumler toplami
    char ascii;

    Node *SearchAndAdd(Node *, const int &);
    Node *SwapWithLeftChild(Node *);
    Node *SwapWithRightChild(Node *);
    bool DeleteNode(Node *&);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    int Height(Node *);
    void PrintLevel(Node *, int);
    bool Search(Node *, const int &);
    AVL();
    bool isEmpty() const;
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    Node *getRoot();
    int Height();
    bool Search(const int &);
    void Clear();
    void Add(const int &);
    void postorderToStack(Node *, Stack *);
    ~AVL();
};

#endif