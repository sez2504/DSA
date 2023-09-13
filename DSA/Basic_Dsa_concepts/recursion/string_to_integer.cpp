#include <iostream>
using namespace std;

#include <cstring>

int stringToNumber_helper(char input[]) {
    if (strlen(input)==1){
        return input[0]-'0';
    }
    int smallAns=stringToNumber_helper(input+1);
    int a = input[0]-'0';
    int ans = smallAns*10+a;
    return ans;
}

int reverse_num (int a){
    int sum=0;
    while (a) {
        int remainder = a%10;
        sum = sum*10+remainder;
        a/=10;
    }
    return sum;
}

int stringToNumber(char input[]){
    return reverse_num(stringToNumber_helper(input));
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
