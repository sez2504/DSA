#include<iostream>
using namespace std;

int count(int n){
    static int a=0;
    if (n){
        count(n/10);
        a++;
    }
    return a;
}

/*alt:-
int count(int n){
    if (n<10){
        return 1;
    }
    return 1+count(n/10);
}
*/

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


