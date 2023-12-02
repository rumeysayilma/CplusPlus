#include <iostream>
using namespace std;

class User {
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;

    //Default Constructor: class oluşturulduğunda otomatik oluşan ctor. 
    //Bu olduğu için class member larına atama yapılmadan çağrılsa bile çakılma olmaz çünkü bu, default atama yapar.
    //User(){} //--> bu bir default constructor dur.

    //Ctor, ait olduğu class ile aynı isme sahip olmalı.
    //Ctor ların return tipi olmaz.
    //Ctor lar, class ın public alanında tanımlanmalı.
    //Default Ctor, herhangi bir parametreye sahip olmaz.
    //Bir class a ait obje oluşturulduğunda default ctor çağrılır.

    //kendi Default ctor umuzu oluşturalım:

    User() {
        FirstName = "nn";
        LastName = "nln";
        Age = 0;
        Email = "not set";
    }


};


class UserParam {
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;


   // parameterized ctor: Default ctor dan farkı, input olarak arguman veya parametre alır.
   // bu aldığı inputları da initialize için kullanır.

    UserParam(string fName, string lName, int age) {
        FirstName = fName;
        LastName = lName;
        Age = age;
        Email = fName+"."+lName+"@mail.com";
    }


};

void GetUserInfo(User u) {

    cout << "FirstName:" << u.FirstName << endl;
    cout << "LastName:" << u.LastName << endl;
    cout << "Age:" << u.Age << endl;
    cout << "Email:" << u.Email << endl;

}


int main()
{

    User user1; // bu oluşturulduğunda default ctor çağrılır
    //constructor olmadan kullanımda her yeni user için arağıdakitanımlamalar tek tek yapılmalı.
    user1.FirstName = "Rumeysa";
    user1.LastName = "YILMAZ";
    user1.Age = 24;
    user1.Email = "Rumeysa@gmail.com";

    GetUserInfo(user1);

    User user2;
    GetUserInfo(user2);


    UserParam user3("rumeysa", "yilmaz", 24);  //param ctor calistirildi

    cout << "FirstName:" << user3.FirstName << endl;
    cout << "LastName:" << user3.LastName << endl;
    cout << "Age:" << user3.Age << endl;
    cout << "Email:" << user3.Email << endl;

    //herhangi bir tipte ctor oluşturduğun an c++ ın otomatik oluşturduğu ctor yok olur. Yani artık otomatik default hiç çağrılamaz.
    //Bunun çözümü, param ctor a ek kendi default ctor umuzu oluşturmaktır.
}