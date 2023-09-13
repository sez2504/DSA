#include <iostream>
#include <string>
using namespace std;

#include <stack>

bool isBalanced(string expression) 
{
    stack<char> s;
    for (int i=0 ; i<expression.size() ; i++){
        if (expression[i] == '[' || expression[i] == '(' ||
            expression[i] == '{') {
            s.push(expression[i]);
        } 
        else if (expression[i] == ']' || expression[i] == ')' || expression[i] == '}') {
            if (s.empty()) {
                return false;
            } 
            else if ( (expression[i] == ')' && s.top() != '(') || (expression[i] == '}' && s.top() != '{' ) || (expression[i] == ']' && s.top() != '[' )) {
                //cout<<"}-{ : "<<')' - '('<<endl;
                cout<<s.top()<<" "<<expression[i]<<endl;
                return false;
            }
            s.pop();
        }
    }
    if (s.empty()){
        return true;
    }
    return false;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}