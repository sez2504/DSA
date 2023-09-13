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

    void add(Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int num = f2.denominator*numerator+f2.numerator*denominator;

        numerator=num;
        denominator=lcm;

        simplify();
    }

    void multiply(Fraction const &f2){
        numerator*=f2.numerator;
        denominator*=f2.denominator;
        simplify();
    }

};

int main()
{
    Fraction f1(10,2);
    Fraction f2(14,4);

    f1.add(f2);

    f1.print();
    f2.print();

    f1.multiply(f2);
    f1.print();
    f2.print();

    return 0;
}