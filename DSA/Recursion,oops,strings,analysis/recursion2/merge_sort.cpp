#include <iostream>
using namespace std;


void merge(int arr[] , int si , int ei){
    int mid = (si+ei)/2;
	int size = ei-si+1;
	int i=si , j= mid+1 , k=si;
	int * temp = new int [1000] ; 
	while (i<mid+1 && j<ei+1){
		if (arr[i]<=arr[j]){
			temp[k]=arr[i];
			i++;
			k++;
		}
		else{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}
	while(i<mid+1){
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<ei+1){
		temp[k]=arr[j];
		j++;
		k++;
	}
	for (int a = 0 ; a<size ; a++){
		arr[a+si]=temp[a+si];
	}
	delete [] temp;
}

void mergeSort_helper(int arr[] , int si , int ei){
	if (si>=ei){
		return;
	}
	int mid = (si+ei)/2;
	mergeSort_helper(arr , si , mid);
    mergeSort_helper(arr , mid+1 , ei);
    merge(arr , si , ei);
}

void mergeSort(int input[], int size){
	mergeSort_helper(input,  0 , size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}