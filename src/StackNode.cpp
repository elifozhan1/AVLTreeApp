/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "StackNode.hpp"

StackNode::StackNode(const int &item, StackNode *next = nullptr)
{
    this->item = item;
    this->next = next;
}

StackNode::~StackNode() {}