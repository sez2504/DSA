#include <iostream>
using namespace std;

class Student{
    public:
    int rollNumber;
    int age;
    static int totalStudents; //belongs to class not object
    //scope resolution operator ::
    Student(){
        totalStudents++;
    }

    static int getTotalStudents(){ //cant use this
        return totalStudents;
    }
};

int Student :: totalStudents = 0; //initialize static data members

int main()
{
    Student s1;
    cout<<s1.rollNumber<<" "<<s1.age<<endl;
    cout<<s1.totalStudents<<endl;  //should not do
    s1.totalStudents=20;
    Student s2;
    cout<<s2.totalStudents<<endl; //should not do
    cout<<Student::totalStudents<<endl;
    Student s3 , s4 , s5;
    cout<<Student::totalStudents<<endl;
    cout<<Student::getTotalStudents<<endl;
    return 0;
}