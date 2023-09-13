#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if (input.size()<=1){
        return;
    }
    int last_element = input.top();
    input.pop();
    reverseStack(input,extra);
    while (!input.empty()){
        int top = input.top();
        input.pop();
        extra.push(top);
    }
    input.push(last_element);
    while(!extra.empty()){
        int top = extra.top();
        extra.pop();
        input.push(top);
    }
}

// void reverseStack(stack<int> &input, stack<int> &extra) {
//     if (input.empty()){
//         return;
//     }
//     while (!input.empty()){
//         extra.push(input.top());
//         input.pop();
//     }
//     input=extra;
//     // delete [] extra;
// }

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}