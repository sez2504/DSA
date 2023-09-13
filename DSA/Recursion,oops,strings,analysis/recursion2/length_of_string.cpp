#include <iostream>
using namespace std;

int length (char s[]){
    if (s[0]=='\0'){
        return 0;
    }
    int smallLength = length(s+1);
    return 1+smallLength;
}

int main()
{
    cout<<length("hejkmmk how")<<endl;
    return 0;
}