#include <iostream>
#include <string>
using namespace std;

#include <stack>

bool checkRedundantBrackets(string expression) {
	if (expression.size()<=2){
		return false;
	}
	stack<char> s;
	int characters=0;
	for (int i=0 ; i<expression.size() ; i++){
		if (expression[i]=='(' && expression[i+2]==')'){
			return true;
		}
		if (expression[i]!=')'){
			s.push(expression[i]);
		}
		else if (expression[i]==')'){
			if (s.empty()){
				return false;
			}
			char topChar = s.top();
			s.pop();
			if (expression[i]==')' && topChar=='('){
				return true;
			}
			else{
				while (s.top()!='('){
					s.pop();
				}
				s.pop();
				//continue;
			}		
		}
	}
	return false;
}

// bool checkRedundantBrackets(string expression) {
// 	int i=0;
// 	bool consecutive_bracket = false;
// 	int brackets_in_consecutive = 0;
// 	while (expression.size()!=0){
// 		if (expression[0]=='(' && consecutive_bracket==false){
// 			if (expression[2]==')' || expression[1]==')'){
// 				return true;
// 			}
// 			if (expression[1]=='('){
// 				consecutive_bracket=true;
// 			}
// 		}
// 		else if (expression[0]=='(' && consecutive_bracket==true){
// 			brackets_in_consecutive++;
// 			if (expression[2]==')' || expression[1]==')'){
// 				return true;
// 			}
// 		}
// 		else if (expression[0]==')' && consecutive_bracket==true){
// 			brackets_in_consecutive--;
// 			if (brackets_in_consecutive==-1){
// 				consecutive_bracket=false;
// 			}
// 			if (expression[1]==')' && consecutive_bracket==false ){
// 				return true;
// 			}
// 		}
// 		expression=expression.substr(1);
// 	}
// 	return false;
// }

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}