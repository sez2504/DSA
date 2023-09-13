#include <iostream>
using namespace std;

void rotate(int *arr, int d, int n)
{
    for (int i=0 ; i<n/2 ;i++){
      int temp =arr[i];
      arr[i]=arr[n-i-1];
      arr[n-i-1]=temp;
  }
  for (int i = 0; i < (n-d)/2 ; i++) { //reverse n-d elements
    int temp =arr[i];
    arr[i]=arr[(n-d)-i-1];
    arr[(n-d)-i-1]=temp;
  }
  for (int i= n-d ; i<(n-d+n)/2 ;i++){ //reverse d elements after n-d
      int temp =arr[i];
      arr[i]=arr[(n-d+n)-i-1];
      arr[(n-d+n)-i-1]=temp;
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

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}