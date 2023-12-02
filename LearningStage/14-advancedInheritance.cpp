#include <iostream>
using namespace std;

class Student {
    //Bu class tan türeyen bir kaç class oluşturacağım-->inheritance
    //base claa genel, derived daha özelleştirilmiş olacak-->art, programing gibi farklı öğrenci tipleri gibi
public:
    string Name;
    int Age;
    char Gender;

    virtual void Study() = 0; //pure virtual method--her derived implement etmek zorunda
    //pure virtual sebebiyle Student abstract class oldu ve base class in instance ı oluşturulamaz(object i)

};

class ProgrammingStudent : public Student {
public:
    void Study() {
        cout << "Learning programming" << endl;
    }

};

class ArtStudent : public Student {
public:
    void Study() {
        cout << "Learning to paint" << endl;
    }    

};

class MusicStudent : public Student {
public:
    void Study() {
        cout << "Learning to play piano and to sing" << endl;
    }   

};

//polimorphism şunu sağlar; Derived class ların objectleri veya subclass larına base class object ilermiş gibi davranılır

int main()
{
    //create array of pointers to Student class:
    //we create array of 3 elements whish is students[3]
    //Inside each element there will be a pointer to student object
    Student* students[3];
    //we can point to anything that is of type Student or any other class that inherits from Student
    students[0]= new ProgrammingStudent();
    students[1]= new ArtStudent();
    students[2]= new MusicStudent();

    for(int i = 0; i <= 2; i++)
    {
        students[i]->Study(); //virtual olduğundan derived class invoke olur
    }

    //allocate ettiğin alanı aynı şekilde deallocate etmen lazım:

    for(int i = 0; i <= 2; i++)
    {
        delete students[i];
    }


    cin.get();
}