#include <iostream>
using namespace std;

int main()
{
    int i=65;
    int * p = &i;
    //char *pc = p; error , implicit
    char * pc = (char*)p; //explicit typecastting
    cout<<*(pc)<<endl;
    cout<<*(pc+1)<<endl;
    cout<<*(pc+2)<<endl;
    cout<<*(pc+3)<<endl;
    cout<<p<<endl<<pc<<endl;
    return 0;
}