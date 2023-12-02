#include <iostream>
using namespace std;

//memory, file gibi şeyler obje destroy edilmeden önce silinmeli. deallocate edilmeli.
// tilda --> option + n

class Book {
public:
    string Title;
    string Author;

    Book(string title, string author)
    {
        Title = title;
        Author = author;
        cout << Title + " Constructor invoked" << endl;


    }
    //Destructor:
    //hep ~ ile başlar, İsmi class ile aynıdır
    //return tipi yoktur.
    //input parametresi almaz, 
    //dtor, class ın member function ı olmalı
    //public: altında bulunmalı
    //sınıf başına 1 dtor bulunabilir.
    ~Book() {
        cout << Title + " Dectructor invoked" << endl;

    }



};


class BookPoint {
public:
    string Title;
    string Author;
    int* Rates; //array in ilk elemanının yerini tutacak
    int RatesCounter;

    BookPoint(string title, string author)
    {
        Title = title;
        Author = author;
        
        RatesCounter = 2;
        Rates = new int [RatesCounter]; // deallocate edilmesi gerekli
        Rates[0] = 4;
        Rates[1] = 5;

        cout << Title + " Constructor invoked" << endl;


    }

    ~BookPoint() {
        delete [] Rates; //array silindi
        Rates = nullptr; //pointer silindi
        cout << Title + " Dectructor invoked" << endl;

    }


};

int main()
{


    Book book1("Millionare Fastlane", "M. J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek Filipek");
    //bunlar, scope ları sonunda destroy edilmiş olmalılar yani application sonunda
    //Yani ~Book otomatik çağrılmış olur
    //descturtor, ctor un çağrıldığı sıranın tersi sıra ile çağrılır.

    //pointer içermeyen class ların descturtor u otomatik oluşturulabilir
    //pointer var ise kendin oluşturman lazım. Yoksa memory leak oluşur.

    BookPoint bookP1("Taylor", "M. J. DeMarco");
    BookPoint bookP2("Swift", "Bartek Filipek");

}