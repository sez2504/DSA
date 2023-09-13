#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char arr1[], char arr2[]) {
    int frequency[256];
    for (int i=0 ; i<256 ; i++){
        frequency[i]=0;
    }
    for (int i=0 ; arr1[i]!='\0'; i++){
        frequency[arr1[i]]++;
    }
    for (int i=0 ; arr2[i]!='\0'; i++){
        frequency[arr2[i]]--;
    }
    for (int i=0 ; i<256 ; i++){
        if (frequency[i]!=0){
            return false;
        }
    }
    return true;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}

/*alt:-
bool isPermutation(char arr1[], char arr2[]) {
    for (int i=0;arr1[i]!='\0';i++){
        int min = arr1[i];
        int minIndex=i;
        //find min element
        for (int j = i+1 ; arr1[j]!='\0' ; j++){
            if (min>arr1[j]){
                min=arr1[j];
                minIndex = j;
            }
        }
        //swap
        int temp = arr1[i];
        arr1[i]=arr1[minIndex];
        arr1[minIndex]=temp;
    }
    for (int i=0;arr2[i]!='\0';i++){
        int min = arr2[i];
        int minIndex=i;
        //find min element
        for (int j = i+1 ; arr2[j]!='\0' ; j++){
            if (min>arr2[j]){
                min=arr2[j];
                minIndex = j;
            }
        }
        //swap
        int temp = arr2[i];
        arr2[i]=arr2[minIndex];
        arr2[minIndex]=temp;
    }
    if (strcmp(arr1,arr2)){
        return false;
    }
    else{
        return true;
    }
}*/