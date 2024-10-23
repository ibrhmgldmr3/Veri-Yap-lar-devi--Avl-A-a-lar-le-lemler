/**
 * @file Yigin.cpp
 * @description Burası yigin kısmı. Burada dinamik dizi ile gerçeklediğim standart yığın işlemleri bulunuyor.
 * @course 1. Öğretim C grubu
 * @assignment 2. Ödev
 * @date 5 Aralık 2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */
#include "Yigin.hpp"
#include <iostream>
using namespace std;

//yığın kurucu fonksiyonu
    Yigin::Yigin()
    {
        kapasite = 5;
        dizi = new int[kapasite];
        tepe = -1;
    }

    //yığun yıkıcı fonksiyonu
    Yigin::~Yigin()
    {
        delete[] dizi;
    }
    //yığın boş mu kontrolü
    bool Yigin::bosMu() const
    {
        return (tepe == -1);
    }
    //yığına veri ekleme fonksiyonu
    void Yigin::ekle(int value)
    {
        tepe++;
        if (tepe == kapasite)
        {
            genislet();
        }
        dizi[tepe] = value;
    }
    //yığından çıkarma fonksiyonu tepe--
    void Yigin::cikar()
    {
        if (bosMu())
        {
            cout << "Yigin bos." << endl;
        }
        else
        {
            tepe--;
        }
    }
    //yığında alan kalmadıysa genişleterek yığına alan açma fonksiyonu
    void Yigin::genislet()
    {
        int *yeniDizi = new int[kapasite +12];
        for (int i = 0; i <= tepe; i++)
        {
            yeniDizi[i] = dizi[i];
        }
        delete[] dizi;
        dizi = yeniDizi;
        kapasite = kapasite+12;
    }
    //yığının tepe değerini getiren fonk
    int Yigin::tepeDeger()
    {
        if (bosMu())
        {
            cout << "Yigin ici bos!!" << endl;
            
            return 0;
        }
        return dizi[tepe];
    }
    //yığının içindeki verileri getiren fonksiyon
    void Yigin::yazdir()
    {
        for(int i=0;i<=tepe;i++)
        {
            cout << dizi[i]<<"  ";
        }
    }
    //yığın içindeki verileri toplaayn fonksiyon
    int Yigin::yiginToplam()
    {
        if (bosMu())
            return tepe;
        int toplam = 0;
        for (int i = 0; i <= tepe; i++)
        {
            toplam += dizi[i];
        }
        return toplam;
    }
    //yığının tepe indeksini döndüren fonksiyon
    int Yigin::tepeIndex()
    {
        return tepe;
    }
 