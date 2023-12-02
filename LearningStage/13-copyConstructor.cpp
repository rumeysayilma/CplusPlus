#include <iostream>
using namespace std;

class Book {
public:
    string Title;
    string Author;
    float* Rates; //dynamic array
    int RatesCounter; //dynamic array in boyutu

    Book(string title, string author)
    {
        Title = title;
        Author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;

    }

    ~Book(){
        delete[]Rates;
        Rates = nullptr;
    }

    //copy ctor, class ın public alanında olmalı
    //return tipi yok
    //class ile aynı isme sahip
    //Input olarak class tipi bir object alır.
    //pass by reference-->orjinal hali pass ediliyor
    //pass by value --> object in kopyası alınıp bu kopya pass edilir

    //copy ctor için pass by ref kullanılır ve const olur ki orjinal değiştirilemesin

    //desctructor sırasında silinmiş array bir kez daha silinmeye çalışılıyor. Fakat o adres artık kullanım dışı kalmış
    //bu, pointer kullanımında ortaya çıkan copy ctor hatalarından biri.
    

    Book(const Book& original) {
        //pointer içermeyen veriler doğrudan koğyalanır. 
        Title = original.Title;
        Author = original.Author;
        //Rates = original.Rates; // Bu pointer içeriyor, bu şekilde kopyalanırsa hata oluşur
        //Bunu yerine point edilen yeni bir adres tanımlanır, bu adrese point ettiği elemanlar kopyalanır
        RatesCounter = original.RatesCounter;
        //pointer kullanılan elemanın tuttuğu elemanlar bu şekilde tek tek koplayanmalı
        Rates = new float[RatesCounter];
        for(int i = 0; i<RatesCounter; i++)
        {
           Rates[i] =  original.Rates[i];
        }



    }


};


void PrintBook(Book book)
{
    cout << "Title: " << book.Title <<endl;
    cout << "Author: " << book.Author <<endl;
    int sum = 0;
    for(int i = 0; i<book.RatesCounter; i++)
    {
        sum += book.Rates[i];
    }
    cout << "Avg rate: " << sum/book.RatesCounter << endl;

}

int main()
{
    Book book1("Millionare Fastlane", "M. J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek Filipek");
    //book1 in aynısından bir tane daha oluşturmak istiyorum.
    //Ayrı ayrı kitap isimleri vermek yerine bu şekilde direkt oluşturmak copy ctor ların ana amacı
     //--> Default copy ctor, hiç tanımlanmadığında otomatik çağrılınca oluşur
    Book book3(book1); //--> Default copy ctor
    //Book book3 = book1; --> bu kullanım da yine copy ctor çağırmak içindir. Yukarıdaki ile farkı yoktur.

    //**1) Yani zaten var olan bir object i temel alarak yeni bir object oluşturulacak ise copy ctor kullanılır.
    //default copy ctor da vardır ama pointerlar ile çalışılıyor ise default kullanılmamalı.

    //**2) Compiler, temporary object oluştururken copy ctor kullanır. 
    //Mesela bir fonksiyona parametre olarak bir object iletiliyorsa(pass by value ile) compiler bu object in kopyasını yapar

    PrintBook(book1); //2. duruma bir örnek Bunu çalıştırırken PrintBook tan önce copy ctor a gidip geçici kopyalama yapar
    PrintBook(book2); 
    PrintBook(book3); 

    //**3) Fonksiyonun return ü bir object ise (by value) yine önce copy ctor çağrılır

    
}