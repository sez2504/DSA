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

    //post-increment
    Fraction operator++(int){
        Fraction fNew(numerator,denominator);
        numerator+=denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction& operator+= (Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int num = f2.denominator*numerator+f2.numerator*denominator;

        numerator=num;
        denominator=lcm;

        simplify();
        return *this;
    }

};

int main()
{
    //nesting not allowed on post increment
    Fraction f1(10,2);
    Fraction f2 = f1++;
    f1.print();
    f2.print();
    Fraction f4(10,3);
    Fraction f3(5,2);
    (f4+=f3)+=f3;
    f4.print();
    f3.print();
    return 0;
}