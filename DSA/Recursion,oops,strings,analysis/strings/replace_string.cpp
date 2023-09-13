#include <iostream>
#include <string>
using namespace std;

int checksequenece(string large , string small) {
    static int i = 0;
    if (small[0]=='\0'){
        return i;
    }
    if (large[0]=='\0'){
        return -1;
    }
    if(small[0]==large[0]){
        checksequenece(large.substr(1), small.substr(1));
    }
    else{
        i++;
        checksequenece(large.substr(1), small);
    }
}

int main()
{
    cout<<checksequenece("my","z")<<endl;
    return 0;
}
