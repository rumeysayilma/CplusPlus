#include <iostream>
#include <list>
using namespace std;


class YoutubeChannel {
    //class içerisine yazılanlar default olarak private olur. Erişim açmak için "public" olduğu belirtilmelidir.
public:
    string NAME;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles; //4 attribute u olan class yarattık

    YoutubeChannel(string name, string ownername) { //This is a constructor. Bundan doyalı default constructor kullanılamaz artık
        NAME = name;
        OwnerName = ownername;
        SubscribersCount = 0;
    }

    void GetInfo() {
        cout<<"Name: " << NAME << endl;
        cout<<"OwnerName: " << OwnerName << endl;
        cout<<"SubscribersCount: " << SubscribersCount << endl;
        cout<<"Videos:" << endl;
    
        for (string videoTitle : PublishedVideoTitles ) //listedeki her eleman için döngü tekrar edilir.
        {
            cout << videoTitle << endl;
        }

    }


};

int main()
{
    /*
    YoutubeChannel YtChannel; //YoutubeChannel türünden object yarattık
    YtChannel.NAME = "Code Beauty";
    YtChannel.OwnerName = "Saldina";
    YtChannel.SubscribersCount = 1800;
    //YtChannel.PublishedVideoTitles = {"C++ for Beginners", "HTML & CSS", "C++ OOP"};
    */
   //Yukarıdaki yerine constructor ile yarattık:
   YoutubeChannel YtChannel("Code Beauty","Saldina");
   YtChannel.PublishedVideoTitles.push_back("C++ for Beginners"); //listeye eleman eklerim
   YtChannel.PublishedVideoTitles.push_back("HTML & CSS");
   YtChannel.PublishedVideoTitles.push_back("C++ OOP");

    YtChannel.GetInfo();

    /* 
    cout<<"Name: " << YtChannel.NAME << endl;
    cout<<"OwnerName: " << YtChannel.OwnerName << endl;
    cout<<"SubscribersCount: " << YtChannel.SubscribersCount << endl;
    cout<<"Videos:" << endl;
   
    for (string videoTitle : YtChannel.PublishedVideoTitles ) //listedeki her eleman için döngü tekrar edilir.
    {
        cout << videoTitle << endl;
    }
    */ //Kodun bu kısmı class method a dahil olabileceğinden class içerisinde bir fonksiyona alındı.
}