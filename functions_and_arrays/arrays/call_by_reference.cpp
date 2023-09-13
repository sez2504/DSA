#include <iostream>
using namespace std;

void increment(int arr[]){
    arr[0]++;
}

int main()
{
    int arr[10]={1,2,3};
    increment(arr);
    cout<<arr[0]<<endl;
    return 0;
}