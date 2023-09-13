#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    for (int i=0 ; i <n ; i++){
        arr[arr[i]]+=n;
    }
    
    for (int i=0 ; i <n ; i++){
        if (arr[i]>=2*n){
            return i;
        }
    }
}

//other way of solving this is using xor

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

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}