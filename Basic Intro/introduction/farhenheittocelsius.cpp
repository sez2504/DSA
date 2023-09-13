#include <iostream>
using namespace std;

int main()
{
    int f;
    cout<<"enter farhenheit\n";
    cin>>f;
    int c = (5/9)*(f-32); //5 /9 will give 0; //int/int is int
    cout << c <<endl;
    c = ((5)*(f-32))/9; 
    cout << c <<endl;
    c = (5.0/9)*(f-32); //float/int is float 
    //double /int is double
    cout << c <<endl;
    cout << (5.0/9)*(f-32) <<endl;
    return 0;
}