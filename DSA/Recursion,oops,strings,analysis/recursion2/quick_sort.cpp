#include<iostream>
using namespace std;

int partition (int arr[] , int si , int ei){
	int count_smaller = 0;
	int x = arr[si];
	for (int i=si ; i<=ei ; i++){
		if (arr[i]<x){
			count_smaller++;
		}
	}
	int count_larger = ei-si;
	int temp = arr[si];
	arr[si]=arr[si+count_smaller];
	arr[si+count_smaller]=temp;
	int i = si , j = ei;
    while (i!=si+count_smaller&&j!=si+count_smaller){
        if (arr[i]<x){
		    i++;
	    }
	    else if (arr[j]>=x){
	    	j--;
	    }
	    else{
	    	int temp = arr[i];
	    	arr[i]=arr[j];
	    	arr[j]=temp;
            i++ ; j--;
	    }
    }
	return si+count_smaller;
}

void quickSort_helper(int input[] , int si , int ei){
	if (si>=ei){
		return;
	}
	int c = partition(input,  si,  ei);
	quickSort_helper(input,  si , c-1);
	quickSort_helper(input ,  c+1 ,  ei);
}

void quickSort(int input[], int size) {
	quickSort_helper(input,  0 ,  size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

