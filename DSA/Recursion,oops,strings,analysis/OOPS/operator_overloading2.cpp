#include <iostream>
using namespace std;

class Fraction{
    private:
    int numerator;
    int denominator;

    public:
    Fraction (int numerator , int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<this->numerator<<"/"<<denominator<<endl;
    }

    void simplify(){
        int hcf;
        int j=min(numerator,this->denominator);
        for (int i=j ; i>=1 ; i--){
            if (numerator%i==0 && denominator%i==0){
                hcf=i;
                break;
            }
        }
        numerator/=hcf;
        denominator/=hcf;
    }


    //pre-increment
    Fraction operator++(){
        numerator+=denominator;
        simplify();
        return *this;
    }
    
    Fraction& operator+(){
        numerator+=denominator;
        simplify();
        return *this;
    }

};

int main()
{
    Fraction f1(10,2);

    f1.print();
    ++f1;
    f1.print();
    Fraction f2 = ++f1;
    f2.print();

    Fraction f4(10,2);
    Fraction f3 = ++(++f4);
    f4.print(); //buffer system
    f3.print();
    
    Fraction f6(10,2);
    Fraction f5 = +(+f6);
    f6.print(); //no buffer system
    f5.print();
    
    return 0;
}