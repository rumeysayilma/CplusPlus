#include <iostream>
#include <string>
#include <list>
using namespace std;

//C++ta özel bir fonksiyon tipi olan "operator functions" tanımlanabilir.
//Bu fonksiyonları, belli bir operatörün belli data tipi için nasıl davranacağını tanımlamak için kullanırız.


//car1 + car2; --> bu işlem için kendi + operatörümüzü tanımlamalıyız. Bu işleme operator overloading denir.

struct YouTubeChannel {
    string Name;
    int SubscribersCount;
    //struct elemanları default olarak public

    YouTubeChannel(string name, int subscribersCount) {
        //contructor, 2 input alıp struct elemanlarını init eder.
        Name = name;
        SubscribersCount = subscribersCount;


    }

};

//function << overload:
ostream& operator<<(ostream& COUT,YouTubeChannel& YTCHANNEL )
{
    //used pass by reference. Yani copyalama olmaz, orjinal halleri aktarılır.
    COUT << "Name:" << YTCHANNEL.Name << endl;
    COUT << "SUBSCRIBERS:" << YTCHANNEL.SubscribersCount << endl;
    return COUT;

}

struct MyCollection{
    list<YouTubeChannel>myChannels;

    void operator+=(YouTubeChannel& CHANNEL) { //buna tekparametre verildi çünkü member function
        this->myChannels.push_back(CHANNEL);
        //MyCollection içindeki myChannels listesine CHANNEL'ı ekle.

    }
};

ostream& operator<<(ostream& COUT, MyCollection& MYCOLLECTION )
{
    for(YouTubeChannel ytchannel: MYCOLLECTION.myChannels )
        COUT << ytchannel << endl;
    return COUT;
}

int main()
{

YouTubeChannel Yt1 = YouTubeChannel("Rumeysa", 100);

YouTubeChannel Yt2 = YouTubeChannel("RUMEYSA SECOND", 2000);

cout << Yt1 << Yt2; //bu şekilde tek line çagırabilmek icin overload tanımı değiştirilmeli.

//normal fonksiyon gibi de çağırabiliriz:
operator<<(cout, Yt1);

MyCollection myCollection;
myCollection += Yt1; //+= overload edildi
myCollection += Yt2;

cout << myCollection; // << operatörü myCollection tipi için de overload edilmeli



}