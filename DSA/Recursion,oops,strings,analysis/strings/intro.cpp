#include <iostream>
using namespace std;

int main()
{
    string s = "abc";
    string s1;
    s1="def";
    cout<<s<<" "<<s1<<endl;
    // cin>>s;
    // cout<<s<<endl;
    getline(cin , s);
    cout << s << endl;
    string *sp = new string;
    *sp= "grp";
    cout << sp << " " << *sp <<endl;
    delete sp;
    cout<<sp<<" "<<*sp<<endl;
    cout << s[0] <<endl;
    string s2=s1+s;
    cout<<s2<<endl;
    cout<<s2.size()<<endl;
    cout<<s2.substr(3,3)<<endl;


    cout<<s2.find("ninjas")<<endl;
    return 0;
}