#include <iostream>
using namespace std;

#include <vector>

int main()
{
    //vector<int> * vp = new vector<int>();
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1]=100;
    v[3]=1000;//dont use ot insert
    v[4]=1024;

    v.push_back(24);
    v.push_back(120);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl;
    cout<<v[6]<<endl;

    cout<<"SIZE : "<<v.size()<<endl;

    v.pop_back();

    for (int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<endl;
    }

    cout<<v.at(2)<<endl;
    cout<<v.at(5)<<endl; //safer

    return 0;
}