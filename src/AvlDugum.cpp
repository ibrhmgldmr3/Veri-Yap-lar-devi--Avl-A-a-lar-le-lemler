/**
 * @file AvlDugum.cpp
 * @description Burası AvlDugum kısmı burada avl ağacına yerleştirilecek düğüm özellikleri bulunuyor. .
 * @course 1. Öğretim C grubu
 * @assignment 2. Ödev
 * @date 5 Aralık 2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */
#include "AvlDugum.hpp"
#include <iostream>
#include <string>
using namespace std;
AvlDugum::AvlDugum()
{
    sagPtr=0;
    solPtr=0;
    sayi=0;
    yukseklik = 1;
}
AvlDugum::AvlDugum(int veri)
{
    sagPtr = 0;
    solPtr = 0;
    sayi = veri;
    yukseklik = 1;
}
/*AvlDugum::~AvlDugum()
{
    cout<<"Dugum Silindi!   -   ";
}*/
