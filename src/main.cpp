/**
 * @file VeriYapilariOdevi
 * @description avl agaclari ve yigitlarla islemler
 * @course 1.ogretim C grubu
 * @assignment 2.odev
 * @date 11.12.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "Program.hpp"

int main()
{
    // veri okuma
    Program program;
    program.readData("./doc/Veri.txt");

    // avl agaclari ile ilgili islemler
    program.processAVLTrees();

    while (program.linkedList.head->next)
    {
        program.compare();
    }

    // son avl ile ilgili bilgileri ekrana yazdirir
    program.printLastAVLInfo();
}