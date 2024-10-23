/**
 * @file AVLAgaclari.cpp
 * @description Burası AVL ağaçlarını yöneten sınıf. Burada ana fonksiyonlar buluyor. AVL ağaçlarının gelen satırlardan oluşturulması,
 *              oluşan ağaçların yığınlarının oluşturulup dizilere aktarılması,yığınların yeniden oluşturulması, son ağacın bulunması gibi ana işlevleri bu sınıf gerçekliyor.
 * @course 1. Öğretim C grubu
 * @assignment 2. Ödev
 * @date 5 Aralık 2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */
#include "AVLAgaclari.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <climits>

using namespace std;
// kurucu fonksiyon
AvlAgaclari::AvlAgaclari()
{
    index = 0;
    veriSayisi = 0;
    ifstream dosya;
    dosya.open("Veri.txt");
    if (dosya.is_open())
    {
        string okuyucu = "";

        while (getline(dosya, okuyucu))
        {
            veriSayisi++; // toplam satir sayisindan oluşacak ağaç sayilarinin elde edilmesi
        }
        
        agaclar = new AvlAgac *[veriSayisi]; // ağaçlari tutacak dizinin oluşturulmasi
        yiginlar = new Yigin *[veriSayisi];  // yiginlari tutacak dizinin olusturulmasi
        AvlAgacDizici();
    }
    dosya.close();
}
// okunan satirlarin dizilere eklenmesi
void AvlAgaclari::ekle(AvlAgac *dugum)
{
    agaclar[index] = dugum;
    Yigin *yigin = new Yigin();
    dugum->postorderYiginAtama(dugum->kok, yigin);
    yiginlar[index] = yigin;
    index++;
    dugum->avlNo = index;
}
// satirlardaki sayilarin okunarak agac dugumlerinin olusturulmasi
AvlAgac *AvlAgaclari::satiriAgacaCevir(string SayiSatiri)
{
    AvlAgac *yeniAgac = new AvlAgac();
    stringstream sayi(SayiSatiri);
    SayiSatiri = SayiSatiri + " ";
    int ss = 0;
    while (sayi >> ss)
    {
        yeniAgac->kok = yeniAgac->ekle(yeniAgac->kok, (ss));
    }
    /*for (int i = 0; i < SayiSatiri.length(); i++)
    {
        if (isdigit(SayiSatiri[i]))
        {
            sayi = sayi + SayiSatiri[i];
        }
        else
        {
            yeniAgac->kok =yeniAgac->ekle(yeniAgac->kok,stoi(sayi));
            sayi="";
        }
    }*/
    return yeniAgac;
}
// satirlari okuyup okunan satirlardan ağaç yapıp diziye atanmasi
void AvlAgaclari::AvlAgacDizici()
{
    ifstream dosya;
    dosya.open("Veri.txt");
    string okuyucu = "";
    int sayac = 0;
    while (getline(dosya, okuyucu))
    {
        ekle(satiriAgacaCevir(okuyucu));
        agaclar[sayac]->postorder(agaclar[sayac]->kok);
        sayac++;
    }
    dosya.close();
}
// ağacın yıkıcı fonksiyonu
AvlAgaclari::~AvlAgaclari()
{
    for (int i = 0; i < veriSayisi; i++)
    {
        if (agaclar[i] != 0)
        {
            delete agaclar[i];
            delete yiginlar[i];
            yiginlar[i] = 0;
            agaclar[i] = 0;
        }
    }
    delete[] agaclar;
    delete[] yiginlar;
}
// ağaçların harflerini dizideki sıraya atanışlarına göre yazdıran fonksiyon
void AvlAgaclari::AvlYazdir()
{
    for (int i = 0; i < veriSayisi; i++)
    {
        if (agaclar[i] != 0)
        {
            cout << agaclar[i]->Harf;
        }
    }
}
// en sona kalan ağacı bulacak fonksiyon
void AvlAgaclari::lastOneStanding()
{
    // kalan ağaç sayısının tutulması
    int kalanAgac = veriSayisi;
    while (kalanAgac > 1)
    {
        // indekslerin atanması ve bulunması
        int kucukIndex = -1;
        int buyukIndex = -1;
        kucukBuyukBulucu(kucukIndex, 'A');
        // indeksi bulunan sayinin yığınından pop işlemi gerçekleştirilmesi
        yiginlar[kucukIndex]->cikar();
        // eğer pop işlemi yığını boşalmışsa silme işlemi gerçeklenmesi
        if (yiginlar[kucukIndex]->bosMu())
        {
            // indeksi bulunan yığının hem ağacının hem de yığının silinmesi
            indexSilici(agaclar, yiginlar, kucukIndex);
            kalanAgac--;       // ağaç sayısının azaltılması
            yeniStackTanimi(); // yığınların yeniden tanımlanması
            if (kalanAgac == 1)
                break;   // eğer ağaç sayısı 1e düşmüşse çıkılması
            AvlYazdir(); // ağaçların yazdırılması
                         // ver ekranın temizlenmesi
            system("CLS");
            //cout << "\033[2J\033[1;1H";
            continue; // küçükten silme işlemi yapıldığı için döngüye baştan başlanmasi
        }
        kucukBuyukBulucu(buyukIndex, 'B');
        // indeksi bulunan sayinin yığınından pop işlemi gerçekleştirilmesi
        yiginlar[buyukIndex]->cikar();
        // eğer pop işlemi yığını boşalmışsa silme işlemi gerçeklenmesi
        if (yiginlar[buyukIndex]->bosMu())
        {
            // indeksi bulunan yığının hem ağacının hem de yığının silinmesi
            indexSilici(agaclar, yiginlar, buyukIndex);
            yeniStackTanimi(); // ağaç sayısının azaltılması
            kalanAgac--;       // kalan ağaç sayısının azaltılması
            if (kalanAgac == 1)
                break;   // eğer ağaç sayısı bire düşmüşse döngüden çıkılması
            AvlYazdir(); // kalan ağaçların tekrar yazddırılması
                         // ekranın temizlenmesi
             system("CLS");
            //cout << "\033[2J\033[1;1H";
        }
    }
    // sona kalan ağacın bulunması ve yazdırılması
    for (int i = 0; i < veriSayisi; i++)
    {
        if (agaclar[i] != 0)
        {
            cout << "=================================" << endl;
            cout << "|" << setw(32) << "|" << endl;
            cout << "|" << setw(17) << "Son Harf: " << agaclar[i]->Harf << setw(14) << "|" << endl;
            int basamakSayisi = 0;
            int tempVeri = agaclar[i]->avlNo;

            while (tempVeri != 0)
              {
                  tempVeri /= 10;
                  ++basamakSayisi;
              }

              if (basamakSayisi == 1)
              {
                  cout << "|" << setw(15) << "AVL NO: " << agaclar[i]->avlNo << setw(16) << "|" << endl;
              }
              else if (basamakSayisi == 2)
              {
                  cout << "|" << setw(15) << "AVL NO: " << agaclar[i]->avlNo << setw(15) << "|" << endl;
              }
              else if (basamakSayisi == 3)
              {
                  cout << "|" << setw(15) << "AVL NO: " << agaclar[i]->avlNo << setw(14) << "|" << endl;
              }
              else if (basamakSayisi == 4)
              {
                  cout << "|" << setw(15) << "AVL NO: " << agaclar[i]->avlNo << setw(13) << "|" << endl;
              }
            //cout << "|" << setw(17) << "AVL NO: " << agaclar[i]->avlNo << setw(12) << "|" << endl;
            cout << "|" << setw(32) << "|" << endl;
            cout << "=================================" << endl;
        }
    }
}
// stacklarden düşülen sayiların tekrar eski haline getirilerek yenilenmesi
void AvlAgaclari::yeniStackTanimi()
{
    for (int i = 0; i < veriSayisi; i++)
    {
        if (agaclar[i] != 0)
        {
            delete yiginlar[i];
            Yigin *yigin = new Yigin();
            agaclar[i]->postorderYiginAtama(agaclar[i]->kok, yigin);
            yiginlar[i] = yigin;
        }
    }
}
// verilen indekse göre silinme işlemini gerçekleyen fonksiyon
void AvlAgaclari::indexSilici(AvlAgac **Dugumler, Yigin **Yiginler, int index)
{
    delete Dugumler[index];
    delete Yiginler[index];
    Yiginler[index] = 0;
    Dugumler[index] = 0;
}
//en verilen harfe göre büyük veya küçük indeksleri buluyor
void AvlAgaclari::kucukBuyukBulucu(int &indeksKB,char Denetleyici)
{
    int kucukSayi = 999999;
    int buyukSayi = -1;
    if(Denetleyici=='A'){
        for (int i = 0; i < veriSayisi; i++)
        {
            // eğer dizilerin o indeksleri boş değilse kontrol edilip en küçük sayının indeksi ile bulunması
            if (yiginlar[i] != 0 && (yiginlar[i]->tepeDeger() < kucukSayi))
            {
                kucukSayi = yiginlar[i]->tepeDeger();
                indeksKB = i;
            }
        }
    }
    else
    {
        for (int i = 0; i < veriSayisi; i++)
        {
            // eğer dizilerin o indeksleri boş değilse kontrol edilip en büyük sayının indeksi ile bulunması
            if (agaclar[i] != 0 && yiginlar[i] != 0)
            {
                if (yiginlar[i]->tepeDeger() > buyukSayi)
                {
                    buyukSayi = yiginlar[i]->tepeDeger();
                    indeksKB = i;
                }
            }
        }
    }
}