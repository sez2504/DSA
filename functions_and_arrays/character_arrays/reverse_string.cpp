#include <iostream>
using namespace std;

int main()
{
    char str[10000];
    cin.getline(str,10000);
    int i=0;
    while (str[i]!='\0')
    {
        i++;
    }
    for (int j=0 ; j<i/2 ;j++){
        int temp = str[j];
        str[j]=str[i-j-1];
        str [i-j-1]=temp;
    }
    cout<<str<<endl;
    return 0;
}