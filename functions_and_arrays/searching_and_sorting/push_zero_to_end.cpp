#include <iostream>
using namespace std;

void pushZeroesEnd(int *arr, int n)
{
    int temp[100000];
    int k=0;
    for (int i=0; i<n ;i++){
        if (arr[i]!=0){
            temp[k]=arr[i];
            k++;
        }
    }
    for (;k<n;k++){
        temp[k]=0;
    }
    for (int i=0; i<n ;i++){
            arr[i]=temp[i];
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
//alt:
/*int nonzero=0;
for(i=0,i<n,i++){
    if(arr[i]!=0){
        swap (arr[i],arr[nonzero]);
        nonzero++;
    }
}
*/