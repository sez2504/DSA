#include <iostream>
using namespace std;

int main()
{
    int a = 100, b = 200;
    int *p = &a, *q = &b;
    p = q;
    cout<<p<<endl<<q<<endl;
    int arr[] = {1, 2, 3, 4};
    //int *pt = arr++; error
    //cout << *pt << endl;
    int c = 50;
    int *ptr = &c;
    int *r = ptr;
    (*r)++;
    cout << c  << endl<< sizeof(ptr)<<endl;
    int f[6] = {1, 2, 3};
    cout << f << " " << &f <<endl;
    int *point = 0;
    int d = 10;
    *point = d;
    cout << *point << endl ;
    return 0;
}