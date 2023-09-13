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

void sort_3_and_5(int * input , int size){
    int three_or_five=0;
    for (int i=0 ; i<size ; i++){
        if (input[i]%3==0 || input[i]%5==0){
            int temp = input[i];
            input[i] = input[three_or_five];
            input[three_or_five]=temp;
            three_or_five++;
        }
    }
    mergeSort(input+three_or_five-1,size-three_or_five+1);
}

bool splitArray(int *input, int size) {
    sort_3_and_5(input,size);
    int sum1=0 , sum2 = 0;
    for (int i=0 ; i<size ; i++){
        if (input[i]%5==0){
            sum1+=input[i];
        }
        else if (input[i]%3==0){
            sum2+=input[i];
        }
        else {
            if (sum1>sum2){
                sum2+=input[i];
            }
            else if (sum1<=sum2){
                sum1+=input[i];
            }
        }
        cout<<"sum1 : "<<sum1;
        cout<<" sum2 : "<<sum2<<endl;
    }
    if (sum1==sum2){
        return true;
    }
    else{
        return false;
    }
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
