#include <iostream>
using namespace std;

class Student{
    public:

    int age;
    int const rollNumber;
    int &x; //age reference variable

    Student(int r , int age) : rollNumber(r) , age(age) , x(this->age){ //putting before initialization
        //rollNumber=r;
    }
};

int main()
{
    Student s1(10,101);
    s1.age=20;
    //s1.rollNumber=101;

    return 0;
}