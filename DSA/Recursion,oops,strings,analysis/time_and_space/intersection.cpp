#include <iostream>
#include <algorithm>
using namespace std;

void merge(int * arr , int si , int ei){
    int mid = (si+ei)/2;
    int size = ei-si+1;
    int i = si ; int j = mid+1; int k =si;
    int * temp = new int [1000];
    while (i<mid+1 && j<ei+1){
        if (arr[i]>arr[j]){
            temp[k]=arr[j];
            k++;
            j++;
        }
        else{
            temp[k]=arr[i];
            k++;
            i++;
        }
    }
    while (i<mid+1){
            temp[k]=arr[i];
            k++;
            i++;
    }
    while (j<ei+1){
            temp[k]=arr[j];
            k++;
            j++;
    }
    for (int a = 0 ; a<size ; a++){
		arr[a+si]=temp[a+si];
	}
	delete [] temp;
}

void mergesort (int * arr ,  int si , int ei){
    if (si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergesort(arr,   si,  mid);
    mergesort(arr ,  mid+1,  ei);
    merge(arr , si , ei);
}

void intersection(int a[], int b[], int n, int m)
{
    mergesort(a, 0 , n-1);
    mergesort(b, 0 , m-1);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            j++;
        }
        else if (b[j] > a[i]) {
            i++;
        }
        else {
 
            // when both are equal
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}


/*alt:-
void intersection(int a[], int b[], int n, int m)
{
    sort(a,a+n);
    sort(b,b+m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            j++;
        }
        else if (b[j] > a[i]) {
            i++;
        }
        else {
 
            // when both are equal
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}
*/

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}