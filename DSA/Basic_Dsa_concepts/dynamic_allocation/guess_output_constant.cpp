#include <iostream>
using namespace std;

int main(){
    int p = 5;
    int const *q = &p;
    p++; //q cant change p but p can change itself
    cout << p << endl;
    return 0;
}