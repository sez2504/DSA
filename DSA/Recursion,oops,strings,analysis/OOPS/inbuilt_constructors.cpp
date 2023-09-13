#include <iostream>
using namespace std;

class Student{
    public : 
    int rollNumber;
    int age;
    
    ~Student(){ //doesnt get called for dynamically created
        cout<<"Destructor called! "<<endl;
    }

    Student(){ 
        cout<<"constructor called! "<<endl;
    }

    //Parametrized
    Student(int rollNumber){
        cout<<"constructor 2 called! "<<endl;
        this->rollNumber=rollNumber;
    }
    
    Student(int a , int r){
        cout<<"constructor 3 called! "<<endl;
        age=a;
        rollNumber=r;
    }

    void diplay(){
        cout<<age<<" "<<rollNumber<<endl;
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        //we can also set a password
        if (a>0){
            age=a;
        }
    }
};

int main()
{
    Student s1(10,101);
    cout<<"S1  : "<<endl;
    s1.diplay();

    //copy constructor
    Student s2(s1);
    cout<<"S2  : "<<endl;
    s1.diplay();

    Student *s3 = new Student(20,2001);
    s3->diplay();

    Student s4(*s3);

    Student * s5 = new Student(*s3);
    Student *s6 = new Student(s1);

    //copy assignment operator
    Student s7(10,1001);
    Student s10 = s7; //copy constructor called.
    Student s8(20,2001);
    Student *s9= new Student(30,3001);

    s8=s7;
    s8.diplay();

    delete s3; //now destructor called for s3 but not s5 , s6 , s9.

    return 0;
}