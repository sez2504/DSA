/*You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. 
Write a function to sort this array/list. Think of a solution which scans the array/list only once 
and don't require use of an extra array/list.*/

#include <iostream>
#include <algorithm>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{
    int count = 0; //counts number of zeroes enountered
    int temp;
    for (int i = 0 ; i<size ; i++){
        if (input[i]==0) { 
            temp=input[i]; //puts next 0 encountered at index (0+count)
            input[i]=input[count];
            input[count]=temp;
            count++;
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
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}