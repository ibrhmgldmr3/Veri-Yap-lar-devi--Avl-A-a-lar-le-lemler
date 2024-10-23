#include "AVLagac.hpp"
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <climits>
class AvlAgaclari
{
    private:
        AvlAgac **agaclar;//dinamik ağaçlar dizisi
        Yigin** yiginlar;//dinamik yiginlar dizisi
        int veriSayisi;//toplam oluşan ağaç ve yiğin sayisi
        int index ;//veri sayısı ile aynı ama bunu toplam
        void indexSilici(AvlAgac **Dugumler, Yigin **Yiginler, int index);// veerilen indekse göre dizilerden o indekste bulunan nesneyi silen fonksiyon
        void ekle(AvlAgac *dugum);//dizilere eleman eklemek için fonksiyon
        void genislet(int);//diziyi genişletmek için fonksiyon
        AvlAgac *satiriAgacaCevir(string);//okunan dosyadaki satırlarda bulunan sayıları ağaca çeviren fonksiyon
        void yeniStackTanimi();//yığınları yeniden oluşturan fonksiyon
        void kucukBuyukBulucu(int &, char);//son harf bulma fonksiyonu(lastOneStanding()) için verilen indekse ve harfe
    public :
        AvlAgaclari();//kurucu fonksiyon
        ~AvlAgaclari();//yıkıcı fonksiyon
        void AvlAgacDizici();//avl ağaçlarını hazır hale getiren fonksiyon 
        void AvlYazdir();//ağaçların harflerini yazdıran fonksiyon
        void lastOneStanding();//en son hangi harfin kalacağını bulan fonksiyon
};