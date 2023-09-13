#include <iostream>
using namespace std;

class Student{
    public : 
    int rollNumber;

    private :
    int age;

    public:
    //this is a constructor
    Student(){ //if this is removed then s1 will give error because inbuilt constructor is only there till we dont make a constructor
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

    void display(){
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
    Student s1;
    s1.display();

    Student s2;
    
    Student * s3 = new Student;
    s3->display();

    cout<<"parametrized constructor demo"<<endl;
    Student s4(10);
    //this is a pointer with memory adress of s4.
    s4.display();

    Student * s5 = new Student(101);
    s5->display();

    Student s6(10,35);
    s6.display();
    
    return 0;
}