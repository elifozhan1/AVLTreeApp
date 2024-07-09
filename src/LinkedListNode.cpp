/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "LinkedListNode.hpp"

LinkedListNode::LinkedListNode(AVL *avl, LinkedListNode *next)
{
    this->avlTree = avl;
    this->next = next;
    this->stack = new Stack();
    this->orderOfTree = 1;
}

LinkedListNode::~LinkedListNode() {}