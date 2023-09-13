#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int val)
{
    int start = 0;
    int end = n-1;
    int mid=(start+end)/2;
    while (start<=end && val!=arr[mid]){
        if (arr[mid]==val){
            break;
        }
        else if (arr[mid]>val){
            end=mid-1;
            mid=(start+end)/2;
        }
        else{
            start=mid+1;
            mid=(start+end)/2;
        }
    }
    if (arr[mid]==val){
        return mid;
    }
    return -1;
}

int main()
{

    // freopen("./Testcases/large/in/input10.txt", "r", stdin);
    // freopen("./Testcases/large/out/output10.txt", "w", stdout);

    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    int t = 1;
    // cin >> t;

    while (t--)
    {
        int val;
        cin >> val;
        cout << binarySearch(input, size, val) << endl;
    }

    delete [] input;
    return 0;
}