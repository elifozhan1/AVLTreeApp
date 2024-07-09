#ifndef Program_hpp
#define Program_hpp

#include <iomanip>
#include <fstream>
#include <sstream>
#include "LinkedList.hpp"

// calisan programin genel kodlari

class Program
{
public:
    LinkedList linkedList;

    void deleteNode(LinkedListNode *);
    void fillStacks();
    void compareAndDeleteStacks();
    Program();
    void readData(const string &);
    void processAVLTrees();
    void compare();
    void printLastAVLInfo();
    void clearAVLTrees();
    ~Program();
};

#endif