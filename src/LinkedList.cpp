/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "LinkedList.hpp"

// bagli liste sinifi avl agaclarini ve yigitlari tutmak icin vardir

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->orderOfTree = 1;
}

// avl agaci ekleme fonksiyonu

void LinkedList::addAVL(AVL *avl)
{
    // agaclar siralarina gore bagli liste dugumlerine yazilirlar
    LinkedListNode *newNode = new LinkedListNode(avl, head);
    newNode->orderOfTree = this->orderOfTree;
    this->orderOfTree++;

    if (head == nullptr)
        head = newNode;

    else
    {
        LinkedListNode *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = NULL;
    }
}

// ilk agaca yani bagli listenin ilk elemanina erismek icin var olan fonksiyon gethead
AVL *LinkedList::getHeadAVL()
{
    if (head != nullptr)
    {
        return head->avlTree;
    }
    else
    {
        cerr << "Hata: Bos bagli liste!" << endl;
        exit(EXIT_FAILURE);
    }
}

LinkedListNode *LinkedList::getHead() const
{
    return head;
}

void LinkedList::clear()
{
    while (head != nullptr)
    {
        LinkedListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

LinkedList::~LinkedList() {}