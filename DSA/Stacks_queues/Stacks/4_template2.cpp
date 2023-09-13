#include <iostream>
using namespace std;

template <typename T , typename V>

class Pair{
    T x;
    V y;

    public:

    void setX ( T x ){
        this->x=x;
    }
    T getX(){
        return this->x;
    }
    void setY ( V y ){
        this->y=y;
    }
    V getY(){
        return this->y;
    }
};

int main()
{
    Pair<int , double> p1;
    p1.setX(100.34);
    p1.setY(34.21);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<Pair<int,int>,int> triplet;
    triplet.setY(20);
    Pair<int,int> p2;
    p2.setX(15);
    p2.setY(16);
    triplet.setX(p2);
    //cout<<triplet.getX()<<endl;
    cout<<triplet.getY()<<endl;
    cout<<triplet.getX().getX()<<endl;
    cout<<triplet.getX().getY()<<endl;
    // Pair<double> p2;
    // p2.setX(100.34);
    // p2.setY(34.21);
    // cout<<p2.getX()<<" "<<p2.gety()<<endl;

    // Pair<char> p3;
    
    return 0;
}