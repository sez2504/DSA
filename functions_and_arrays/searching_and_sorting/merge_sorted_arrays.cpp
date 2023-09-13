#include <iostream>
using namespace std;

void merge(int *arr1, int n1, int *arr2, int n2, int *ans)
{
    int count_arr1=0;
    int count_arr2=0;
    int size1=n1;
    int size2=n2;
    int max1=arr1[n1-1];
    int max2=arr2[n2-1];
    int i=0 , j =0;
    for (int count = 0;  count<n1+n2 ;  count++){
        
        if (arr1[i]<=arr2[j] || count_arr2==n2){
            count_arr1++;
            ans[count]=arr1[i];
            i++;
        }
        else if(arr2[j]<arr1[i] || count_arr1==n1){
            count_arr2++;
            ans[count]=arr2[j];
            j++;
        }
    }
}
/*actual:-
void merge(int *arr1, int n1, int *arr2, int n2, int *ans)
{
    int i=0 , j =0,k=0;
    while (i<n1 && j<n2){
        if (arr1[i]<=arr2[j]){
            ans[k]=arr1[i];
            i++; k++;
        }
        else{
            ans[k]=arr2[j];
            j++; k++;
        }
    }
    while (i<n1){
        ans[k]=arr1[i];
        i++; k++;
    }
    while (j<n2){
        ans[k]=arr2[j];
        j++; k++;
    }
}*/

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size1;
		cin >> size1;

		int *arr1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> arr1[i];
		}

		int size2;
		cin >> size2;

		int *arr2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> arr2[i];
		}

		int *ans = new int[size1 + size2];

		merge(arr1, size1, arr2, size2, ans);

		for (int i = 0; i < size1 + size2; i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;
		delete[] arr1;
		delete[] arr2;
		delete[] ans;
	}
}