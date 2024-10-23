#include "AvlDugum.hpp"
#include "Yigin.hpp"
using namespace std;
class AvlAgac
{
private:
    int AvlToplam = 0;

public:
    
    AvlAgac();
    ~AvlAgac();
    //AvlAgac* agacSonraki; bağlı liste denemeleri
    AvlDugum* kok;
    int avlNo;// ağaç numarası
    char Harf;//yapraklar harici kalan sayıların toplamından oluşan top
    int yukseklik(AvlDugum*);//ağacın yüksekliği
    int maks(int,int);//2 sayıyı karşılaştırıp büyüğünü alan fonksiyon
    AvlDugum* sagaYatir(AvlDugum* );//ağacı dengelemek için sorunlu düğümleri sağa döndüren fonksiyon
    AvlDugum* solaYatir(AvlDugum*);//ağacı dengelemek için sorunlu düğümleri sola döndüren fonksiyon
    int dengedeMi(AvlDugum *);//denge kontrolü  
    AvlDugum* ekle(AvlDugum*,int);//ağaca düğüm ekleme fonksiyonu
    void postorder(AvlDugum *);//postorder ile harf bulma
    void AvlAgacininKokunuKurut(AvlDugum *);// postorder yöntemi ile düğümleri sildirip ağacı silme
    AvlDugum *yeniDugum(int );//yeni düğüm oluşturucu fonksiyon
    void postorderYiginAtama(AvlDugum *, Yigin *);//yığına yaprakları atayan fonksiyon
    //char HarfCevirme(int );// harf oluşturucu fonksiyon
};