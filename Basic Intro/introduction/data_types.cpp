#include <iostream>
using namespace std;

int main()
{
    int a = 10; //2 or 4 bytes , usully 4
    int b ,c;
    //range of int is (-2^(n-1) to 2^(n-1)-1)
    //n is number of bits (32 for int)
    //negative int stored with 2 compliment
    //5=0101
    //1'=1010
    //2'=1'+1
    //2'=1011  //starting 1 is a sign bit for negative
    //to get int from binary of negative take 2' again
    //unsigned int only positive int stors from 0 to 2^n-1
    b = 5;
    c=a+b;
    cout << c << endl;

    float d = 1.23; //4bytes //mantessa and exponenet 1.01101*2^2=101.101 
    //01101 is mantessa
    //2 is exponent
    //double has 8 bytes
    bool e = true;
    char f = 'f'; //1 byte

    int size = sizeof(int);
    cout << size << endl;
    cout << e << endl;

    unsigned int w = -123;
    //w=-123 which is -ve
    //it takes 2' but initial 1 is not treated as sign bit and 2' number is treated like +ve
    //example -123=000000000000000001001
    //2'=11111111111111010
    //these many 1 in start make number very large
    cout << w << endl;

    double q = 6/4; //this will be one due to integer division (int/int)
    cout<< q <<endl;

    double t = 55.5;
    int y = 55;
    //t = t % 10; //error cant do integer opeator on double
    y = y % 10;
    cout << a << " "  << b;
    //!b will be false for any value of b other than zero

    return 0;
}