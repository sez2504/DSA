#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char arr[]) {
    int spaceIndex[1000000];
    spaceIndex[0]=-1;
    int count=1;
    int i;
    for (i = 0; arr[i]!=0 ; i++){
        if (arr[i]==' '){
            spaceIndex[count]=i;
            count++;
        }
    }
    spaceIndex[count]=i;
    count++;
    for (int i=0 ; i < count ; i++){
        int wordstart = spaceIndex[i]+1;
        int wordEnd = spaceIndex[i+1];
        for (int j= wordstart ; j<(wordstart+wordEnd)/2 ; j++){
            int temp = arr[j];
            arr[j]=arr[wordEnd+wordstart-j-1];
            arr[wordstart+wordEnd-j-1]=temp;
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}
/*alt:
#include <algorithm>
#include <cstring>
int prev=-1;
for (i=0;i<=strlen(arr);i++){
    if (arr[i]==' ' || arr[i]=='\0'){
        reverse(arr+prev+1,arr+i); //this is reverse(start,end);
        //reverse reverses elements from start to end. 
        prev=i;
    }
}*/