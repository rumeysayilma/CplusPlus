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

class CookingYoutubeChannel: public YoutubeChannel {
// CookingYoutubeChannel, YoutubeChannel dan inherit etti
// Böylece YoutubeChannel ın sahip olduğu her şeye sahip olmuş olur.Hem private hem public
//türetme tanımında kullanılan "public", YoutubeChannel da public olan her şeyin türetilmiş classta da public olacağını belirtir
//YoutubeChannel --> Base class
//CookingYoutubeChannel --> Derived(türetilmiş class)
//Constructor ı kendine ait olmalı.
public:
    CookingYoutubeChannel(string name, string ownername):YoutubeChannel(name,ownername) { //constructor
    //name ve ownername initialize işlemini yapmış bir sınıftan türediği için bu işlemş yapmayız.
    //Bunların işlemi için inputları base fonksiyona gönderdik (call ctor)
    }
    //Sadece bu class a özgü bazı member lar da olabilir.
    void Practice() {
        cout << OwnerName <<" is practicing cooking, leaqrning new recipes" << endl;
     
    }

};



int main()
{
    CookingYoutubeChannel ytFoodChannel("Amy's Kitchen", "Amy");
    ytFoodChannel.PublishVideo("Apple Pie");
    ytFoodChannel.PublishVideo("Chocolate Cake");
    ytFoodChannel.Subscribe();
    ytFoodChannel.Subscribe();
    
    ytFoodChannel.GetInfo();
    ytFoodChannel.Practice();


}