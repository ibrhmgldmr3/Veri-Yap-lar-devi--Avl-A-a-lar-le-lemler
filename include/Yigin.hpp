#ifndef Yigin_hpp
#define Yigin_hpp
class Yigin
{
public:
    // tuttuğu sayi değeri
    int tepe;
    int kapasite;//yığının kapasitesi
    int *dizi; // sayilari tutacak bir dizi // dizi araciligi ile tutmak daha hizli olacaktir
    Yigin();
    ~Yigin();
    void ekle(int);//ekleme fonksiyonu
    void cikar();//diziden eleman atmak icin cikarma fonksiyonu
    int tepeDeger();//en tepedeki degere ulasmak icin fonksiyon
    bool bosMu()const;//dizi dolu mu bos mu kontrolu
    int yiginToplam();//yigin icindeki degerler toplami
    void genislet();//dizinin kapasitesi dolmuşsa genişletecek fonksiyon
    int tepeIndex();//tepe indeksini döndüren fonk
    void yazdir();// yığının içindeki sayıları getiren fonk
};
#endif // !Yigit_hpp