#include <iostream>
#include <list>
using namespace std;


class YoutubeChannel {
    //class içerisine yazılanlar default olarak private olur. Erişim açmak için "public" olduğu belirtilmelidir.
private:
    string NAME;
    
    int SubscribersCount;
    list<string> PublishedVideoTitles; //4 attribute u olan class yarattık
protected:
    string OwnerName;   //Derived sınıfın erişebilmesi için bu yapı kullanıldı.
    int ContentQuality;

public:
    YoutubeChannel(string name, string ownername) { //This is a constructor. Bundan doyalı default constructor kullanılamaz artık
        NAME = name;
        OwnerName = ownername;
        SubscribersCount = 0;
        ContentQuality = 0;
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

    void CheckAnalytics(){
        if(ContentQuality < 5)
        {
            cout << NAME << "has bad quality." <<endl;
        }
        else
        {
            cout << NAME << "has good quality." <<endl;
        }
    }
};

class CookingYoutubeChannel: public YoutubeChannel {

public:
    CookingYoutubeChannel(string name, string ownername):YoutubeChannel(name,ownername) { //constructor

    }
    //Sadece bu class a özgü bazı member lar da olabilir.
    void Practice() {
        cout << OwnerName <<" is practicing cooking, leaqrning new recipes" << endl;
        ContentQuality++;
    }

};

class SingersYoutubeChannel: public YoutubeChannel {

public:
    SingersYoutubeChannel(string name, string ownername):YoutubeChannel(name,ownername) { //constructor
    }
    
    void Practice() {
        cout << OwnerName <<" is singing" << endl;
        ContentQuality++;
    }

};

int main()
{
    CookingYoutubeChannel ytFoodChannel("Amy's Kitchen", "Amy");
    CookingYoutubeChannel ytSongChannel("Lana's Songs", "Lana");

    ytFoodChannel.Practice();
    ytSongChannel.Practice();
    ytSongChannel.Practice();
    ytSongChannel.Practice();
    ytSongChannel.Practice();
    ytSongChannel.Practice();
    ytSongChannel.Practice();

    //polymorphism ve pointer ların kesiştiği yere geldik.
    //you can assign to a pointer of a base class, an adress of derived class.
    //pointer kullanarak method invoke etme:
    YoutubeChannel * yt1 = &ytFoodChannel;
    YoutubeChannel * yt2 = &ytSongChannel;  //bu şekilde method da invoke edebilirim.

    yt1->CheckAnalytics();
    yt2->CheckAnalytics();



}