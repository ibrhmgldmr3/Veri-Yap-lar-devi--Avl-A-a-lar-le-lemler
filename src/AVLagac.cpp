/**
 * @file AVLAgac.cpp
 * @description Burası AVL ağaç sınıf. Bir avl ağacının sahip olduğu özellikler bu sınıfta. Kendi kendini dengelemesi, düğüm eklemeleri,
 *              postorder ile yapraklar harici düğümler toplamını bulup harfini çıkarması ve aynı şekilde yaprakları okuyarak yığına ataması.
 * @course 1. Öğretim C grubu
 * @assignment 2. Ödev
 * @date 5 Aralık 2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */
#include <iostream>
#include "AVLagac.hpp"
using namespace std;

AvlAgac::AvlAgac()
{
    kok=0;
   // agacSonraki=0;
    avlNo=0;
    Harf=0;
}
int AvlAgac::yukseklik(AvlDugum* Dugum)
{
    if (Dugum == 0)
        return 0;
    return Dugum->yukseklik;
}
int AvlAgac::maks(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
//düğümleri sağa yatirip düzeltmek için
AvlDugum* AvlAgac::sagaYatir(AvlDugum*Dugum)
{
        AvlDugum *anaDugum = Dugum->solPtr;
        AvlDugum *gecici = anaDugum->sagPtr;

        // saga cevirme isleminin gerceklenmesi
        anaDugum->sagPtr = Dugum;
        Dugum->solPtr = gecici;

        // yuksekliklerin düzenlenmesi
        Dugum->yukseklik = maks(yukseklik(Dugum->solPtr), yukseklik(Dugum->sagPtr)) + 1;
        anaDugum->yukseklik = maks(yukseklik(anaDugum->solPtr),yukseklik(anaDugum->sagPtr)) +1;
        // yeni kok un dondurulmesi
        return anaDugum;
}
//ağacı sola yatirip düzeltmek için
AvlDugum *AvlAgac::solaYatir(AvlDugum *Dugum)
{
    AvlDugum *anaDugum = Dugum->sagPtr;
    AvlDugum *gecici = anaDugum->solPtr;

    // sola cevirme isleminin gerceklenmesi
    anaDugum->solPtr = Dugum;
    Dugum->sagPtr = gecici;

    // yuksekliklerin düzenlenmesi
    Dugum->yukseklik = maks(yukseklik(Dugum->solPtr),yukseklik(Dugum->sagPtr)) +1;
    anaDugum->yukseklik = maks(yukseklik(anaDugum->solPtr),yukseklik(anaDugum->sagPtr)) +1;

    // yeni kok un dondurulmesi
    return anaDugum;
}
// Dugumun denge durumunun kontrolu
int AvlAgac::dengedeMi(AvlDugum*Dugum)
{
    if (Dugum == 0)
        return 0;
    return yukseklik(Dugum->solPtr) - yukseklik(Dugum->sagPtr);
}
//AVL ağacına dugum eklemek icin
AvlDugum *AvlAgac::ekle(AvlDugum *dugum, int sayi)
{
    //Normal ekleme işlemlerini izler
    if (dugum == 0)
        return (yeniDugum(sayi));
    if (sayi < dugum->sayi)
        dugum->solPtr = ekle(dugum->solPtr, sayi);
    else if (sayi > dugum->sayi)
        dugum->sagPtr = ekle(dugum->sagPtr, sayi);
    else 
        return dugum;
    //yukseklik ve denge durumlarını kontrol eder
    dugum->yukseklik = 1 + maks(yukseklik(dugum->solPtr),yukseklik(dugum->sagPtr));
    int balance = dengedeMi(dugum);

    //dengesizlik varsa denge durumuna getirir
    // sol sol durumu
    if (balance > 1 && (sayi < dugum->solPtr->sayi))
        return sagaYatir(dugum);
    // sag sag durumu
    if (balance < -1 && (sayi > dugum->sagPtr->sayi))
        return solaYatir(dugum);
    // sol sag durumu
    if (balance > 1 && (sayi > dugum->solPtr->sayi))
    {
        dugum->solPtr = solaYatir(dugum->solPtr);
        return sagaYatir(dugum);
    }
    // sag sol durumu
    if (balance < -1 && (sayi < dugum->sagPtr->sayi))
    {
        dugum->sagPtr = sagaYatir(dugum->sagPtr);
        return solaYatir(dugum);
    }
    //dugumu geri dondur
    return dugum;
}
//post-order okuma fonksiyonu ve harfini bulma
void AvlAgac::postorder(AvlDugum *Dugum)
{
    if (Dugum != 0)
    {
        postorder(Dugum->solPtr);
        postorder(Dugum->sagPtr);
        if (!(Dugum->sagPtr == 0 && Dugum->solPtr == 0))
        {
            AvlToplam = AvlToplam + Dugum->sayi;
        }
        
    }
    Harf = char(AvlToplam % (90 - 65 + 1) + 65);
    
}
//yıkıcı fonksiyon
AvlAgac::~AvlAgac()
{
    AvlAgacininKokunuKurut(kok);
    kok = 0;
}
//ağacın düğümlerini postorder ile gezerek silme fonksiyonu
void AvlAgac::AvlAgacininKokunuKurut(AvlDugum *Dugum)
{
    if (Dugum == 0)
        return;

    AvlAgacininKokunuKurut(Dugum->solPtr);
    AvlAgacininKokunuKurut(Dugum->sagPtr);

    delete Dugum;
    Dugum=0;
}
//yeni düğüm oluşturma fonksiyonu
AvlDugum* AvlAgac::yeniDugum(int sayi)
{
    AvlDugum* dugum=new AvlDugum(sayi);
    return dugum;
}
//post-order ile okuyarak yığına sayıları atayan fonksiyon
void AvlAgac::postorderYiginAtama(AvlDugum *Dugum,Yigin *yigin)
{
    if (Dugum != 0)
    {
        postorderYiginAtama(Dugum->solPtr,yigin);
        postorderYiginAtama(Dugum->sagPtr,yigin);
        if(Dugum->sagPtr==0 && Dugum->solPtr==0)
        {
            yigin->ekle(Dugum->sayi);
        }
    }
}
