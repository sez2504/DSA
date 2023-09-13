#include <iostream>
using namespace std;

bool same(int *arr , int n ){
    int i=1;
    bool ans = false;
    while (i<n){
        if (arr[i]==arr[0]){
            int temp = arr[1];
            arr[1]=arr[i];
            arr[i]=temp;
            ans=true;
            return true;
            break;
        }
        i++;
    }
    return ans;
}

int findUnique(int *arr, int n) {
    for (int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    if (n==1){
        int a=arr[0];
        cout<<"a is "<<a<<endl;
        return a;
    }
    bool ans = same(arr,  n);
    cout<<ans<<endl;
    if (ans){
        return findUnique(arr+2,n-2);
    }
    else{
        int a=arr[0];
        cout<<"a is "<<a<<endl;
        return a;
    }
    return arr[0];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}