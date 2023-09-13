#include <iostream>
using namespace std;

int main()
{
      int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++;
    int *r = *q;
    (*r)++;
    cout << a << " " << b << endl;
    int e = 100;
    int *ptr = &e;
    int **qtr = &ptr;
    int f = (**qtr)++ + 4;
    cout << e << " " << f << endl;
     int arr[] = {4, 5, 6, 7};
    int *pt = (arr + 1);
    cout << *arr + 9 <<endl;
    float arr2[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr2[0];
    float *ptr2 = ptr1 + 3;
    cout<<*ptr2<<" ";
    cout<< ptr2 - ptr1;
    return 0;
}