/*A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.*/

#include <iostream>
using namespace std;

int staircase(int n){
    if (n==0||n==1){
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else if (n==3){
        return 4;
    }
    int smallans1=staircase(n-1);
    //1 possible way to climb 1 step
    int smallans2=staircase(n-2);
    //2 ways to climb 2 steps
    int smallans3=staircase(n-3);
    //4 ways to climb 3 steps
    return smallans1+smallans2+smallans3;
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
