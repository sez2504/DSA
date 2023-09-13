#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }
    for (int i = 0 ; i<n-1 ; i++){
        int min = arr[i];
        int minIndex=i;
        //find min element
        for (int j = i+1 ; j<n ; j++){
            if (min>arr[j]){
                min=arr[j];
                minIndex = j;
            }
        }
        //swap
        int temp = arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
    for (int i = 0 ; i<n ; i++){
        cout << arr[i] <<" ";
    }
    return 0;
}