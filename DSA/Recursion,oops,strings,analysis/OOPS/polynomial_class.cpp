/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations

/*Implement a polynomial class, with the following properties and functions.
Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] 
as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current 
capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is 
within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. 
For more clarity, refer sample test cases*/
#include <vector>
#include <climits>
#include <iostream>
using namespace std;


class Polynomial {
    int nextIndex;
    int capacity;

    public:
    int *degCoeff;
    Polynomial(){
        degCoeff=new int[5];
        for (int i=0 ; i<5 ; i++){
            degCoeff[i]=0;
        }
        nextIndex=0;
        capacity=5;
    }

    Polynomial (int * degCoeff , int capacity){
        this->degCoeff = new int [capacity];
        for (int i=0 ; i<capacity ; i++){
            this->degCoeff[i]=degCoeff[i];
        }
        this->capacity=capacity;
    }

    Polynomial (Polynomial const &p){
        this->degCoeff=new int[p.capacity];
        for (int i=0 ; i<p.capacity ; i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
        this->nextIndex=p.nextIndex;
    }

    void operator=(Polynomial const &p){
        this->degCoeff=new int[p.capacity];
        for (int i=0 ; i<p.capacity ; i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
        this->nextIndex=p.nextIndex;
    }

    void setCoefficient(int degree , int coefficient){
        if (degree>=capacity){
            int temp = capacity;
            while (degree>=capacity){
                capacity*=2;
            }
            int * newData = new int[capacity+1];
            for (int i=0 ; i<temp ; i++){
                newData[i]=degCoeff[i];
            }
            for (int i=temp ; i<=capacity ; i++){
                newData[i]=0;
            }
            delete [] degCoeff;
            degCoeff=newData;
        }
        degCoeff[degree]=coefficient;
    }      
    
    Polynomial operator+(Polynomial const &p2){
        int minimum = min(capacity,p2.capacity);
        int maximum = max(capacity,p2.capacity);
        Polynomial p3;
        for (int i=0 ; i<minimum ; i++){
            p3.setCoefficient(i,(degCoeff[i]+p2.degCoeff[i]));
        }
        for (int i=minimum ; i<maximum ; i++){
            if (capacity>minimum){
                p3.setCoefficient(i,degCoeff[i]);
            }
            else{
                p3.setCoefficient(i,p2.degCoeff[i]);
            }
        }
        for (int i=maximum ; i<p3.capacity ; i++){
            p3.setCoefficient(i,  0);
        }
        return p3;
    }
    
    Polynomial operator-(Polynomial const &p2){
        int minimum = min(capacity,p2.capacity);
        int maximum = max(capacity,p2.capacity);
        Polynomial p3;
        for (int i=0 ; i<minimum ; i++){
            p3.setCoefficient(i,(degCoeff[i]-p2.degCoeff[i]));
        }
        for (int i=minimum ; i<maximum ; i++){
            if (capacity>minimum){
                p3.setCoefficient(i,degCoeff[i]);
            }
            else{
                p3.setCoefficient(i,-p2.degCoeff[i]);
            }
        }
        return p3;
    }
    
    Polynomial operator*(Polynomial const &p2) const{ //issue max degree takes is 3
        int max_p2;
        int max_p1;
        for (int i=capacity-1 ;i>=0 ; i--){
            if (degCoeff[i]!=0){
                max_p1=i;
                break;
            }
        }
        
        for (int i=p2.capacity-1 ;i>=0 ; i--){
            if (p2.degCoeff[i]!=0){
                max_p2=i;
                break;
            }
        }

        Polynomial p3;
        for (int i=0 ; i<=max_p1 ; i++){
            for (int j=0 ; j<=max_p2 ; j++){
                p3.setCoefficient(i+j,(p3.degCoeff[i+j]+(degCoeff[i]*p2.degCoeff[j])));
            }
        }
        
        return p3;
    }

    void print(){
        for (int i=0 ; i<capacity+1 ; i++){
            if (degCoeff[i]!=0){
                cout<<degCoeff[i]<<'x'<<i<<' ';
            }
        }
    }
};




//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            //Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
        //     // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}