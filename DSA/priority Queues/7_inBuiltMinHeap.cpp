#include <iostream>
using namespace std;

#include <queue>


int main()
{
    priority_queue<int , vector<int> , greater<int> > pq;
    pq.push(16);
    pq.push(45);
    pq.push(72);
    pq.push(38);
    cout<<"size : "<<pq.size()<<endl;
    cout<<"top : "<<pq.top()<<endl;
    while (!pq.empty()){
        cout<<pq.top()<< " ";
        pq.pop();
    }
    cout<<endl;    
    return 0;
}