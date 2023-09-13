/*Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.*/

#include<iostream>
using namespace std;

bool checksequenece(char large[] , char*small) {
    if (small[0]=='\0'){
        return true;
    }
    if (large[0]=='\0'){
        return false;
    }
    if(small[0]==large[0]){
        checksequenece(large+1, small+1);
    }
    else{
        checksequenece(large+1, small);
    }
}


int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
