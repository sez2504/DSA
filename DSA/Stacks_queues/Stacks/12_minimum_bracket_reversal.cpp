#include <iostream>
#include <string>
using namespace std;

#include <stack>

int countBracketReversals(string input) {
	if (input.size()%2!=0){
		return -1;
	}
	int reverse=0;
	stack<char> s;
	for (int i=0 ; i<input.size() ; i++){
		if (s.empty()){
			s.push(input[i]);
        } 
		else if (s.top()==input[i]) {
            //reverse++;
            s.push(input[i]);
        } 
		else if (input[i]=='{'){
			s.push(input[i]);
		}
		else{
			s.pop();
		}
    }
	while (!s.empty()){
		char c1 = s.top();
		s.pop();
		char c2 = s.top();
		s.pop();
		if (c1==c2){
			reverse++;
        } 
		else if (c1 == '{' && c2 == '}'){
			reverse+=2;
		}
    }
	//cout<<"elements : "<<elements<<endl;
	return reverse;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}