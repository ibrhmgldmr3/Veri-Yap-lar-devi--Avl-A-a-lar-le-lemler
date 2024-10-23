#ifndef AvlDugum_hpp
#define AvlDugum_hpp
#include <string>
class AvlDugum
{
public:
    // tuttuğu sayi değeri
    int sayi;
    int yukseklik;//yukseklik değeri
    // çocuk işaretçileri
    AvlDugum *sagPtr;
    AvlDugum *solPtr;
    AvlDugum();
    AvlDugum(int);
   // ~AvlDugum();
};
#endif