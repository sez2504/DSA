#include <iostream>
using namespace std;

void fun(int a[]) {
    cout << a[0] << " ";
}

int main() {
    int a[] = {1, 2, 3, 4};
    fun(a + 1); //1st element is 0th element in function
    cout << a[0];
}