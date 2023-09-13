#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100];
    int temp;
    for (int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }
    for (int i = 0 ; i<n/2 ; i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }    
    for (int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout<<"\n";
    for (int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }
    int i = 0 , j = n-1;
    while (i<j){ //alternate
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }    
    for (int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout<<"\n";
    return 0;
}