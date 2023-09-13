#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr , int n , int num){
	sort (arr,arr+n);
	int si = 0;
	int ei = n-1;
	int numPairs=0 ;
	while (si<ei)
	{
		if (arr[si]+arr[ei]< num){
			si++;
		}
		else if (arr[si]+arr[ei] > num){
			ei--;
		}
		else{
			int startelement = arr[si];
			int endelement = arr[ei];
			if (startelement==endelement){
				int totalElementsFromStartToEnd = (ei-si)+1;
				numPairs+= (totalElementsFromStartToEnd*(totalElementsFromStartToEnd-1))/2;
				return numPairs;
			}
			int tempsi = si+1;
			int tempei = ei-1;
			while (tempsi <= tempei && arr[tempsi]==startelement)
			{
				tempsi++;
			}
			while (tempei >= tempsi && arr[tempei]==endelement)
			{
				tempei--;
			}
			int totalElementsFromStart = (tempsi-si);
			int totalElementsFromEnd = (ei-tempei);
			numPairs+=(totalElementsFromStart*totalElementsFromEnd);
			si=tempsi;
			ei=tempei;
		}
	}
	return numPairs;
}

/*alt:-
int pairSum(int *arr, int n, int num)
{
	if (n==1||n==0){
		return 0;
	}
	int smalloutput = pairSum(arr+1,  n-1,  num);
	int count = 0;
	int a = arr[0];
	for (int i=1 ; i<n ; i++){
		if ((a+arr[i])==num){
			count++;
		}
	}
	return count+smalloutput;
}*/

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}