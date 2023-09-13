#include <iostream>
using namespace std;

//path is constant not storage.

void g(int const & a){
    //a++: error
}

void f(const int * p){
    //(*p)++; error
}

int main()
{
    const int i=10;
    int const i2 = 10;
    //i=12 is error and we have to initialise it there itself.
    int j=12; //j has read and write acces
    const int& k = j; // j gave k read only access
    //k++ is an error.
    j++; //this is fine.
    //storage is not constant but path through k is constant but path through j is fixed
    cout<<k<<endl;
    const int j2 = 12;
    int const& k2 = j2;

    int const j3=123; //j3 has read only access
    //int &k3 = j3; error //j3 cant give k3 read and write access

    int const a = 10;
    int const *p = &a;
    int b=12;
    int const *p2 = &b;
    cout<<*p2<<endl;
    b++;
    cout<<*p2<<endl;
    int const *ptr;
    ptr=&a; //ptr is pointing to a constant but is not a constant
    ptr=&b;
    int c = 10;
    int d =12;
    int * const ptr2=&c; //ptr is a constant pointer but variable is not constant i.e. adress is constant.
    (*ptr2)++;
    cout<<c<<endl;
    //ptr2=&d;
    int const * const ptr3 = &c; //constant pointer to a constant variable.
    return 0;
}