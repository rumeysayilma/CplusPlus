//Pure virtual function un base class'ta implementasyonu olmayacak, 
//ama tüm derived class ların o fonksiyon içinimplementasyon yapmasını zorunlu tutacak.


#include <iostream>
using namespace std;


class Instrument {
public:
    virtual void MakeSound() = 0; //pure virtual function olusturuldu böylece Instrument class abstract oldu.
    // Abstract class tanımı: en az 1 pure virtual function ı olan classlardır.

};

class Accordion: public Instrument{
public:
    void MakeSound(){
        cout<<"Accordion is playing \n" ; 
    }


};

class Piano: public Instrument{
public:
    void MakeSound(){
        cout<<"Piano is playing \n" ; 
    }


};

int main()
{

   Instrument* i1 = new Accordion();
   i1->MakeSound(); 

    Instrument* i2 = new Piano();
   i2->MakeSound(); 

   Instrument* instruments[2]= {i1,i2};

    for(int i=0; i<2; i++) {
        instruments[i] -> MakeSound();
    }


    system("pause>0");
}