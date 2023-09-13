#include <iostream> //preprocessor directive
using namespace std;
#define PI 3.14
#define MULTIPLY(a,b) a*b
#define SQUARE(x) x*x

int a;
void f(){
    cout<<a<<endl;
    a++;
}

int main()
{
    int r;
    cin>>r;
    cout<<PI*r*r<<endl;
    a=10;
    f();
    cout<<a<<endl;
    cout <<MULTIPLY(2+3,3+5)<<endl; //compiler sees this as 2+3*3+5
    int x = 36 / SQUARE(6);
    cout << x<<endl;
    return 0;
}
//avoid global variable as much as possible.