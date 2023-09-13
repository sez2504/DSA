#include <iostream>
using namespace std;

int main()
{
    char name[100];
    cout << "enter your name : " << endl;
    cin >> name; //enter abc
    name[3]='d'; //replaces null
    name[4]= 'x';
    cout << name <<endl;
    name[1]='\0';
    return 0;
}