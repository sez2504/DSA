#include <iostream>
using namespace std;

int binarySearch_helper(int input[],  int x , int si , int ei){
    int mid = (si+ei)/2;
    if(si>ei){
        return -1;
    }
    if (input[mid]==x){
        return mid;
    }
    if (x>input[mid]){
        binarySearch_helper(input,  x, mid+1,  ei);
    }
    else{
        binarySearch_helper(input,  x, si,  mid-1);
    }
}
int binarySearch(int input[], int size, int element) {
   return binarySearch_helper(input,  element, 0,  size-1);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
