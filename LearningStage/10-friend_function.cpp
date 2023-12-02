#include <iostream>
using namespace std;


//friend function has access to private and protected members of a class.
//bunu kullanıyoruz çünkü private olmasını istediğimiz 
//ama aynı zamanda belli kişiler ile paylaşmak istediğimiz bilgiler var.
//Friend class, inherit ile aktarılmaz

class EquilateralTriangle {
private:    
    float a;
    float circumference;
    float area;

public:
    void setA(float length) {
        a = length;
        circumference = a * 3;
        area = (1.73 * a * a) / 4;
    }
    //friend yapmak istediğimiz fonksiyonun declaration ını bu şekilde belirtiriz:
    friend void PrintResults(EquilateralTriangle);

    //friend class tanımlamak:
    friend class HomeWork;
};

//friend class:
class HomeWork {
public:
    void PrintResults_class(EquilateralTriangle Et) {
    cout << "circumference = " << Et.circumference << endl;
    cout << "area = " << Et.area << endl;
}

};


//friend function:
void PrintResults(EquilateralTriangle Et) {
    cout << "circumference = " << Et.circumference << endl;
    cout << "area = " << Et.area << endl;
}

int main()
{
    EquilateralTriangle et;
    et.setA(3);

    PrintResults(et);

    HomeWork H;
    H.PrintResults_class(et);






}