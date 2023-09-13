#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    int i=0,nextZero=0,nextTwo=n-1;
    while (i<=nextTwo){
        if (arr[i]==0){
            int temp = arr[nextZero];
            arr[nextZero]=arr[i];
            arr[i]=temp;
            i++;
            nextZero++;
        }
        else if (arr[i]==2){
            int temp = arr[nextTwo];
            arr[nextTwo]=arr[i];
            arr[i]=temp;
            nextTwo--;
        }
        else{
            i++;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}

/*
alt:-
void sort012(int *arr, int n)
{
    int count_0=0;
    int count_2=0;
    for (int i=0 ; i<n ; i++){
        if (arr[i]>1){
            count_2++;
        }
        else if (arr[i]<1){
            count_0++;
        }
        arr[i]=2;
    }
    for(int i=0 ; i<n ;i++){
        arr[i]=1;
    }
    for (int i=0 ; i<count_0 ; i++){
        arr[i]=0;
    }
    for (int i=n-1 ; i>n-count_2-1 ; i--){
        arr[i]=2;
    }
}*/