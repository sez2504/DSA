#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    int count = 0;
    while (c != '$'){
        count++;
        cin >> c;
    }
    cout << count << endl;
    //cin ignores \n and whitespace and \t
    //cin.get() does not
    c=cin.get();
    count = 0;
    while (c != '$'){
        count++;
        c=cin.get();
    }
    cout << count << endl;
    return 0;
}