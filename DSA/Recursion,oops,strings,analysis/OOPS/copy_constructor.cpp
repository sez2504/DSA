#include <iostream>
#include <cstring>
using namespace std;

class Student{
    int age;

    public : 

    char *name;
    
    Student(int age , char *name){
        this->age=age;
        //shallow copy
        //this->name=name;

        //deep copy
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    Student(Student const &s){ //copy constructor
        this->age=s.age;
        this->name = new char [strlen(s.name)+1];
        strcpy(this->name,s.name);
    }

    void display(){
        cout<<age<<" "<<name<<endl;
    }
};

int main()
{
    char name[] = "abcd";
    Student s1 (20,name);
    s1.display();

    Student s2(s1);

    s2.name[0]='x';
    s1.display();
    s2.display();

    return 0;
}