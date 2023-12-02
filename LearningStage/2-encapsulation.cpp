#include <iostream>
#include <list>
using namespace std;


class YoutubeChannel {
    //class içerisine yazılanlar default olarak private olur. Erişim açmak için "public" olduğu belirtilmelidir.
private:
    string NAME;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles; //4 attribute u olan class yarattık
public:
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

    void Subscribe() {
        SubscribersCount++;
    }

    void Unsubscribe() {
        if(SubscribersCount > 0)
        {
            SubscribersCount--;
        }
        
    }

    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);

    }

};

int main()
{

   YoutubeChannel YtChannel("Code Beauty","Saldina");

   YtChannel.PublishVideo("C++ for Beginners"); //listeye eleman eklerim
   YtChannel.PublishVideo("HTML & CSS"); 
   YtChannel.PublishVideo("C++ OOP"); 


    YtChannel.Subscribe();
    YtChannel.Subscribe();
    YtChannel.Subscribe();

    YtChannel.GetInfo();

}