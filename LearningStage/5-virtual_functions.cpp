//Virtual function, base class'ta tanımlanır; derived classta redefined edilir. 
//Yani ikisinin implementasyonu farklı olur.
//Virtual functionların ana amacı, runtime polimorphisim sağlamaktır.
//Virtual functionlar, implementasyon olarak en türetilmiş olanı kullandırır.

#include <iostream>
using namespace std;


class Instrument {
public:
    virtual void MakeSound(){
        cout<<"Instrument is playing \n" ; 
    }

};

class Accordion: public Instrument{
public:
    void MakeSound(){
        cout<<"Accordion is playing \n" ; 
    }


};

int main()
{
    /*
    Instrument i1;
    i1.MakeSound();
    */

   Instrument* i1 = new Accordion();
   i1->MakeSound(); //Bunu virtual yapmadan bu şekilde kullanırsam base class çağrılır.

   // -> Bu işaret class memberlara erişimi sağlar

    system("pause>0");
}