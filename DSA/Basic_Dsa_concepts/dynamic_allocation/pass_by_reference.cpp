#include <iostream>
using namespace std;

void increment (int& n){
    n++;
}

//bad practice
int& f(int n){
    int a =n;
    cout<<&a<<endl;
    return a;
}

//bad practice
int * f2(){
    int i=10;
    cout<<&i<<endl;
    return &i;
}

int main()
{
    int i=10;
    int& j=i; //adress of j and i is same . i and j are same , must be initialised simultaneously.
    int k=50;
    j=k;
    cout<<j<<" "<<i<<endl;
    i++;
    cout<<j << ' ' <<i <<endl;
    increment(i);
    cout<<j << ' ' <<i <<endl;
    int& h=f(i); //problem: scope of a within function , so how is it accessing it's memory?
    //the memory is not with us anymore and data can be changed
    cout<<h<<endl<<&h<<endl;
    int * ptr=f2();
    cout<<ptr<<endl;
    return 0;
}