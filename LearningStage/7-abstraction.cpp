#include <iostream>
using namespace std;

//Kahve makinesi ile kahve yaparken makinenin işleyişini veya farklı makinelerin aynı kahveyi yaparkenki
//işleyişini bilmeyiz.Sadece latte istiyorsak tuşa basarız. Arkadaki process bizim için abstracted olmuştur.

//Biz de kodlama ile komplex detayları simple prosedürler arkasına saklarız.
//Abstracted olmuş şeyler end -user için sık değişen şeyler olmaz.Arkaplan işleyişi değişebilir.

//Abstract class ın en az 1 pure virtual function ı olur.
//Abstract class ların inctance ı yaratılamaz. Ama pointer ı yaratılabilir.


class Smartphone {
public:
    virtual void TakeASelfie() = 0; 
    //TakeASelfie implementasyonu Smartphone class ında değil bundan inherit eden classlarda olacak.

};

class Android : public Smartphone {

public:
    void TakeASelfie() {
        cout<<"Android Selfie\n";
    }

};


class IPhone: public Smartphone {
public:
    void TakeASelfie() {
        cout<<"IPHONE taking a selfie\n";
    }

};

int main()
{

Smartphone * s1 = new Android(); //base class pointer, point to derived class
s1->TakeASelfie();

Smartphone* s2 = new IPhone();
s2->TakeASelfie();






    system("pause>0");

}