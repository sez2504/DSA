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

    Fraction add(Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int num = f2.denominator*numerator+f2.numerator*denominator;

        Fraction fNew(num,lcm);
        fNew.simplify();
        return fNew;
    }
    Fraction operator+(Fraction const &f2) const{
            int lcm = denominator*f2.denominator;
            int num = f2.denominator*numerator+f2.numerator*denominator;

            Fraction fNew(num,lcm);
            fNew.simplify();
            return fNew;
        }

    void multiply(Fraction const &f2){
        numerator*=f2.numerator;
        denominator*=f2.denominator;
        simplify();
    }

    Fraction operator*(Fraction const &f2) const{
        int n=numerator*f2.numerator;
        int d=denominator*f2.denominator;
        Fraction fNew(n,d);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2) const {
        return (numerator==f2.numerator && denominator==f2.denominator);
    }

};

int main()
{
    Fraction f1(10,2);
    Fraction f2(15,4);
    Fraction f3=f1.add(f2);
    Fraction f4=f1+f2;
    Fraction f5=f1*f2;

    if (f3==f4){
        cout<<"equal"<<endl;
    }
    else{
        cout<<"not equal"<<endl;
    }

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();

    return 0;
}