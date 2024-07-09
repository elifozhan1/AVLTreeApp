/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "Stack.hpp"

Stack ::Stack()
{
    topOfStack = nullptr;
    firstStack = nullptr;
}

// bos mu
bool Stack ::isEmpty() const
{
    return topOfStack == nullptr;
}

// eleman ekleme
void Stack ::push(const int &item)
{
    topOfStack = new StackNode(item, topOfStack);
    firstStack = topOfStack;
}

// eleman cikarma
void Stack ::pop()
{
    if (isEmpty())
        throw "Stack bos";

    topOfStack = topOfStack->next;
}

// yigit doldurma
void Stack ::fill()
{
    topOfStack = firstStack;
}

// en bastaki elemani gosterir
const int &Stack ::top() const
{
    return topOfStack->item;
}

// yigit bosaltma
void Stack ::makeEmpty()
{
    while (!isEmpty())
        pop();
}

Stack ::~Stack()
{
    makeEmpty();
}