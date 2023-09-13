#include <iostream>
using namespace std;

class Student{
    public : int rollNumber;
    public : int age;
    private :
    int age2;
    public:
    void diplay(){
        cout<<age2<<" "<<rollNumber<<endl;
    }
    int getAge(){
        return age2;
    }
    void setAge(int a){
        //we can also set a password
        if (a>0){
            age2=a;
        }
    }
};

int main()
{
    ///creates object stastically
    Student s1;
    s1.age=18;
    s1.rollNumber=101;

    s1.setAge(19);
    cout <<"Age 2 : "<<s1.getAge()<<endl;
    s1.diplay();

    //dynamically
    Student * s2 = new Student;
    (*s2).age=24;
    s2->rollNumber=104;

    return 0;
}