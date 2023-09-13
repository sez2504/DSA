#include <iostream>
using namespace std;

#include <unordered_map>
#include <string>

int main()
{
    unordered_map<string , int> ourMap;

    //insert -> key value pair
    pair<string , int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"]=2;

    //find or access
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;
    //cout<<ourMap.at("ghi")<<endl; error
    cout<<ourMap["ghi"]<<endl; //inserts and return 0

    //check presence
    if (ourMap.count("ghi")>0){
        cout<<ourMap["ghi"]<<endl;
    }

    //size:
    cout<<ourMap.size()<<endl;

    //erase:
    ourMap.erase("ghi");

    cout<<ourMap.size()<<endl;
    
    return 0;
}