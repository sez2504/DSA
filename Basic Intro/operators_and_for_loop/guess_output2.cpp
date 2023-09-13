#include <iostream>
using namespace std;
int main() {
    int a = 10;
    if(a > 5) {
        int a = 100;
    }
    else {
        int a = 110;
    }
    cout << a << endl;
    if(a > 5) {
        a = 100;
    }
    else {
        a = 110;
    }
    cout << a << endl;
}