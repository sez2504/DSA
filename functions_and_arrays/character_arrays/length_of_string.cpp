#include <iostream>
using namespace std;

int length (char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}

int main()
{
    char str[10000];
    cin>>str;
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    cout<<i<<endl;
    cout << length(str) << endl;
    return 0;
}