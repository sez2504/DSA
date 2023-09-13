#include <iostream>
using namespace std;

void reverseStringWordWise(char arr[]) {
    int words;
    int i=0;
    while (arr[i]!='\0'){
        i++;
    }
    for (int j=0 ; j<i/2 ;j++){
        int temp = arr[j];
        arr[j]=arr[i-j-1];
        arr[i-j-1]=temp;
    }
    int wordlength=0;
    int spaceindex[1000];
    spaceindex[0]=-1;
    int indexCount=1;
    for (int k=0 ; k<i ; k++){
      if (arr[k] == ' ') {
        spaceindex[indexCount] = k;
        indexCount++;
      }
    }
    spaceindex[indexCount]=i;
    indexCount++;
    for (int k=0 ; k<indexCount ; k++){
        cout<<spaceindex[k]<<endl;
    }
    for (int m=0 ; m<indexCount ; m++){
        // cout<<spaceindex[m]<<endl;
        int wordStart=spaceindex[m]+1;
        int wordEnd = spaceindex[m+1];
        //cout << wordEnd << endl << wordStart <<endl << m <<endl;
        for (int l=wordStart ; l<(wordStart+wordEnd)/2 ; l++){
            cout<<l<<endl;
            int temp = arr[l];
            arr[l]=arr[wordEnd+wordStart-l-1];
            //cout << arr[wordEnd-l-1]<<endl <<arr[l]<<endl;
            arr[wordEnd+wordStart-l-1]=temp;
        }
    }
        
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
