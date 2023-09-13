#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

int atoi(char a)
{
    int i=a-'0';
    return i;
}
char itoa(int i)
{
    char c='a'+i-1;
    return c;
}

void printAllPossibleCodes(string input , string output) {
    if(input.size()==0)
   {
       cout<<output<<endl;
       return;
   }
   char ch1=itoa(atoi(input[0]));
   printAllPossibleCodes(input.substr(1),output+ch1);
   if (input.size()>1){
        int sum = (atoi(input[0]))*10+atoi(input[1]);
        if (sum >=10 && sum < 27){
            char ch2=itoa(sum);
            printAllPossibleCodes(input.substr(2),output+ch2);
        }
   }
}

int main(){
    string input;
    cin >> input;
    string output;
    printAllPossibleCodes(input,output);
    return 0;
}
