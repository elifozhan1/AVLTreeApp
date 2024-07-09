/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "Node.hpp"

Node::Node(const int &vr)
{
    data = vr;
    left = nullptr;
    right = nullptr;
    height = 0;
}

Node::~Node() {}