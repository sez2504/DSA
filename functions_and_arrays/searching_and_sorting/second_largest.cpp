#include <iostream>
using namespace std;

#include <climits>

int findSecondLargest(int *arr, int n)
{
    int max=INT_MIN;
    int secondMax = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        if (arr[i]>max){
            secondMax=max;
            max=arr[i];
        }
        else if(arr[i]>secondMax && arr[i] < max){
            secondMax=arr[i];
        }
    }
    return secondMax;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}