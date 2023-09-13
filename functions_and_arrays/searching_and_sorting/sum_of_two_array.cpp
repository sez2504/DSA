/*Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. 
Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). 
The idea here is to represent each array/list as an integer in itself of digits N and M.
You need to find the sum of both the input arrays/list treating them as two integers and put the result 
in another array/list i.e. output array/list will also contain only single digit at every index.*/

#include <iostream>
using namespace std;

void sumOfTwoArrays(int *arr1, int n1, int *arr2, int n2, int *output)
{
    int num1 = 0;
    for (int i = 0 ; i<n1 ; i++){
        num1=num1*10+arr1[i];
    }
    int num2 = 0;
    for (int i = 0 ; i<n2 ; i++){
        num2=num2*10+arr2[i];
    }
    int sum = num1+num2;
    // cout<<sum<<endl;
    int max ;
    if (n1>n2){
        max=n1;
    }
    else{
        max=n2;
    }
    // cout<<max<<endl;
    if (sum>=(max+1)*10){
        for (int i=max ; i>=0 ; i--){
            int remainder = sum%10;
            // cout<<remainder<<endl;
            sum/=10;
            output[i]=remainder;
        }
    }
    else{
        for (int i=max ; i>=1 ; i--){
            int remainder = sum%10;
            sum/=10;
            output[i]=remainder;
        }
        output[0]=0;
    }
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size1;
		cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
		{
			cin >> input1[i];
		}

		int size2;
		cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
		{
			cin >> input2[i];
		}

		int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];

		sumOfTwoArrays(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}

		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}

	return 0;
}