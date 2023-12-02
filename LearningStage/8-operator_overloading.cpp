#include <iostream>
#include <string>
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
void operator<<(ostream& COUT,YouTubeChannel& YTCHANNEL )
{
    //used pass by reference. Yani copyalama olmaz, orjinal halleri aktarılır.
    COUT << "Name:" << YTCHANNEL.Name << endl;
    COUT << "SUBSCRIBERS:" << YTCHANNEL.SubscribersCount << endl;

}

int main()
{

YouTubeChannel Yt1 = YouTubeChannel("Rumeysa", 100);
//cout << Yt1; --> burada insertion operatörü Yt1 e nasıl etki edeceğini bilemez. 
//Bunu yapabilmek için insertion operatörü overload ederiz.

cout << Yt1;

YouTubeChannel Yt2 = YouTubeChannel("RUMEYSA SECOND", 2000);



}