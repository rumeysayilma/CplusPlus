#include <iostream>
using namespace std;

class Smartphone {
public:
    virtual void TakeASelfie() =0; //bu fonksiyon pure virtual function. böylece class abstract olabilir.
    //Smartphone dan inherit eden class lar bu fonksiyonu implement etmek zorunda. Böylece soyutlama yapmış oluruz.
};

class Android:public Smartphone { //Smartphone'dan inherit ettik
public:
    void TakeASelfie() {
        cout << "Android selfie\n";
    }

};

class IPhone:public Smartphone {
public:
    void TakeASelfie() {
        cout << "IPhone selfie \n";
    }

};

int main()
{

Smartphone* s1 = new Android(); //base class pointer oluşturduk. Bu, türetilmiş sınıfı göstermekte.
s1->TakeASelfie();  //Nokta yerine bu sembol kullanılır. Çünkü sınıfın member ına erişmek istiyoruz. ve s1 bir pointer

Smartphone* s2 = new IPhone();
s2->TakeASelfie();

//system("pause>0");


}