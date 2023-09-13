#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char arr[]) {
    int notDuplicate=0;
    for (int i=0 ; arr[i]!='\0' ; i++){
        if (arr[i+1]==arr[i]){
            continue;
        }
        int temp=arr[i];
        arr[i]=arr[notDuplicate];
        arr[notDuplicate]=temp;
        notDuplicate++;
    }
    arr[notDuplicate]='\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}