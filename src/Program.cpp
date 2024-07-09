/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "Program.hpp"

// dugum sil fonksiyonudur bagli listeden eleman silmeye yarar
void Program::deleteNode(LinkedListNode *node)
{
    LinkedListNode *deleteNode = NULL;
    deleteNode = node->next;

    if (node->next->next)
        node->next = node->next->next;

    else
        node->next = NULL;

    delete deleteNode;
}

// yigitlari doldur fonksiyonu program icerisinde tekrar eden karsilastirma islemleri sirasinda yigitlarin ilk degerlerini almalarini saglar
void Program::fillStacks()
{
    LinkedListNode *node = linkedList.getHead();

    while (node != NULL)
    {
        cout << node->avlTree->ascii;
        node->stack->fill();
        node = node->next;
    }

    system("CLS");
}

// yigitlarin en ustunde bulunan elemanlarinin kiyaslanmasi islemlerinde kullanilir
void Program::compareAndDeleteStacks()
{
    int biggerNumber = 0; // dusuk bir deger olmali
    int smallerNumber = 10000; // yuksek bir deger olmali
    int biggerNumberIndex = 0;
    int smallerNumberIndex = 0;

    LinkedListNode *current = linkedList.getHead();

    while (current != NULL)
    {
        
        // listede gezerken en kucuk degerinden kucuk olan her sayi yeni en kucuktur
        if (smallerNumber > current->stack->top())
        {
            smallerNumber = current->stack->top();
            smallerNumberIndex = current->orderOfTree;
        }


        // listede gezerken en buyuk degerinden buyuk olan her sayi yeni en buyuktur
        if (biggerNumber < current->stack->top())
        {
            biggerNumber = current->stack->top();
            biggerNumberIndex = current->orderOfTree;
        }

        current = current->next;
    }

    // en kucuk sayi listede en buyukten oncedir
    if (smallerNumberIndex < biggerNumberIndex)
    {
        current = linkedList.getHead();

        if (smallerNumberIndex == current->orderOfTree)
        {
            current->stack->pop();

            if (current->stack->isEmpty())
            {
                LinkedListNode *deleteNode = current;
                linkedList.head = current->next;
                delete deleteNode;
                fillStacks();
                return;
            }
        }

        while (current->next->orderOfTree != biggerNumberIndex)
        {

            if (current->next->orderOfTree == smallerNumberIndex)
            {
                current->next->stack->pop();

                if (current->next->stack->isEmpty())
                {
                    deleteNode(current);
                    fillStacks();
                    return;
                }

                if (biggerNumber < current->next->stack->top())
                {
                    current->next->stack->pop();

                    if (current->next->stack->isEmpty())
                    {
                        deleteNode(current);
                        fillStacks();
                    }
                    return;
                }
            }

            current = current->next;
        }

        current->next->stack->pop();

        if (current->next->stack->isEmpty())
        {
            deleteNode(current);
            fillStacks();
            return;
        }
    }

    // en buyuk sayi listede en kucukten oncedir
    else if (biggerNumberIndex < smallerNumberIndex)
    {
        current = linkedList.getHead();

        LinkedListNode *biggerNode = current;
        LinkedListNode *biggerNodeBefore = current;

        if (biggerNumberIndex == current->orderOfTree)
        {
            biggerNode = linkedList.getHead();
        }

        while (current->next->orderOfTree != smallerNumberIndex)
        {
            if (current->next->orderOfTree == biggerNumberIndex)
            {
                biggerNode = current->next;
                biggerNodeBefore = current;
            }

            current = current->next;
        }

        current->next->stack->pop();

        if (current->next->stack->isEmpty())
        {
            deleteNode(current);
            fillStacks();
            return;
        }

        if (current->next->stack->top() > biggerNumber)
        {
            current->next->stack->pop();

            if (current->next->stack->isEmpty())
            {
                deleteNode(current);
                fillStacks();
                return;
            }
        }

        else
        {
            biggerNode->stack->pop();

            if (biggerNode->stack->isEmpty())
            {
                if (biggerNode == linkedList.head)
                {
                    LinkedListNode *deleteNode = current;
                    linkedList.head = current->next;
                    delete deleteNode;
                    fillStacks();
                    return;
                }

                else
                {
                    deleteNode(biggerNodeBefore);
                    fillStacks();
                    return;
                }
            }
        }
    }

    else
    {
        current = linkedList.getHead();

        current->next->stack->pop();

        if (current->next->stack->isEmpty())
        {
            deleteNode(current);
            fillStacks();
            return;
        }
    }
}

Program::Program() {}

void Program::readData(const string &fileName)
{
    ifstream file(fileName);
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int number;

        AVL *avl = new AVL();

        while (iss >> number)
        {
            avl->Add(number);
        }

        linkedList.addAVL(avl);
    }

    file.close();
}

void Program::processAVLTrees()
{
    LinkedListNode *current = linkedList.getHead();
    int avlNumber = 1;

    while (current != nullptr)
    {

        AVL *avl = current->avlTree;
        Stack *stack = current->stack;
        avl->postorderToStack(avl->getRoot(), stack);

        avl->ascii = avl->sumOfNodes % (90 - 65 + 1) + 65;

        current = current->next;
    }
}

void Program::compare()
{
    compareAndDeleteStacks();
}

// son avlnin bilgilerini ekrana yazdirir
void Program::printLastAVLInfo()
{
    int lastAVLNumber = linkedList.getHead()->orderOfTree;
    int lastAVLAscii = linkedList.getHead()->avlTree->ascii % (90 - 65 + 1) + 65;

    cout << "\n==============================\n";
    cout << "|                            |\n";
    cout << "|                            |\n";
    cout << "| Son Karakter: " << setw(13) << left << linkedList.getHead()->avlTree->ascii << "|\n";
    cout << "| AVL No      : " << setw(13) << left << lastAVLNumber << "| \n";
    cout << "|                            |\n";
    cout << "|                            |\n";
    cout << "==============================\n";
}

void Program::clearAVLTrees()
{
    linkedList.clear();
}

Program::~Program() {}