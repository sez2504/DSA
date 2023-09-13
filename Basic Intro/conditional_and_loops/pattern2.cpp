#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    int val = 1;
    while (i<=n){
        int j = 1; //j keeps track of the number of elements
        int spacenum = n-i;
        while (spacenum>=0){
            cout << "  ";
            spacenum--;
        }
        while (j<=i){
            cout<<val<<" ";
            j++;
            val++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}