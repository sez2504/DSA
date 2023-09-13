#include <iostream>
using namespace std;

//static memory in stack. (cant access in runtime)
//dynamic memory in heap. (can access in runtime)
//dynamic memory doesnt get over within the scope , doesnt automatically get released , keeps increasing memory storage.

int main()
{
    int i=10;
    int *p=new int; //4 bytes made in heap
    //8 byte pointer made in stack
    *p=i;
    cout << *p <<endl;
    int n;
    cin>>n;
    int * parr=new int[50];  //200 byte in heap , 8 byte in stack.
    int * arr= new int[n]; //this is fine.
    arr[0]=10;
    delete p; //frees 4 byte in heap , parr doesnt get deleted , parr still points to same deallocated memory location
    delete [] parr; //frees 200 bytes in heap.

    return 0;   
}