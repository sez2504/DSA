#include <iostream>
using namespace std;

int main()
{
    int a = 15 , b = 20;
    int ror = a|b , rand = 15&30 , rxor = 15^30 , rnot = ~a , rls = a<<2 , rrs = a>>2;
    cout << ror << endl << rand << endl << rxor << endl << rnot << endl << rls << endl << rrs << endl;
    return 0;
}