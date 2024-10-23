/**
 * @file main.cpp
 * @description Burası main kısmı ağaçları yönetecek AvlAgaclari sinifindan bir nesne oluşturup işlemleri gerçekliyor. Ekstra olarak geçen zamanı da hesaplıyor.
 * @course 1. Öğretim C grubu
 * @assignment 2. Ödev
 * @date 5 Aralık 2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */
#include <iostream>
#include "AVLAgaclari.hpp"
#include "chrono"



using namespace std;
int main()
{
    auto start_time=std::chrono::high_resolution_clock::now();
    AvlAgaclari Agaclar;
    //Agaclar->AvlYazdir();
    //system("PAUSE");
    Agaclar.lastOneStanding();
    //delete Agaclar;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
    cout<<duration.count();
}