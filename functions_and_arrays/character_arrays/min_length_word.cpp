#include<iostream>
using namespace std;

void minLengthWord(char arr[], char output[]){
	int spaceIndex[100000];
	spaceIndex[0]=-1;
	int count = 1;
	int i;
	for (i = 0 ; arr[i]!='\0' ; i++){
		if (arr[i]==' '){
			spaceIndex[count]=i;
			count++;
		}
	}
	spaceIndex[count]=i;
    int wordLenth;
    int wordlengthMin=100000;
    for (int i=0 ; i<count ; i++){
        int wordstart=spaceIndex[i]+1;
        int wordend = spaceIndex[i+1]-1;
        wordLenth=wordend-wordstart+1;
        if (wordLenth<wordlengthMin){
            wordlengthMin=wordLenth;
            int j;
            for (j=0 ; j<wordlengthMin ; j++){
                cout<<spaceIndex[i]<<' '<<j<<' ';
                output[j]=arr[spaceIndex[i]+1+j];
            }
            cout<<endl;
            output[j]='\0';
        }
    }
    cout<<endl<<wordlengthMin<<endl;;
}

int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
