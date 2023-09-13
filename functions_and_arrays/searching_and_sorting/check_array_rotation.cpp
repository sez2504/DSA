/*You have been given an integer array/list(ARR) of size N.
 It has been sorted(in increasing order) and then rotated by some number 'K' 
 (K is greater than 0) in the right hand direction.
Your task is to write a function that returns the value of 'K', 
that means, the index from which the array/list has been rotated.*/

#include <iostream>
using namespace std;

int arrayRotateCheck(int *arr, int n)
{
    int flag = 0;
    for (int i=0 ; i<n-1 ; i++){
        if (arr[i]<arr[i+1]){
            flag++;
        }
    }
        if (n!=0 && flag!=n-1){ //flag checks if it is all in ascending order
        int count = 0;
        for (;count<n-1;count++){
            if (arr[count]>arr[count+1]){
                break;
            }
        }
        return count+1;
    }
    else{return 0;}
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

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}