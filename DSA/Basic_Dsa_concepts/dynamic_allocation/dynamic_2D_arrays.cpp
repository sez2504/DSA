#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    //creating 2D array
    int ** p = new int*[r];
    for (int i=0 ; i<r ; i++){
        p[i] = new int[i+1]; //unequal no of column in each row.
        for (int j=0 ; j<c ; j++){
            cin >> p[i][j];
        }
    }
    for (int i=0 ; i<c ; i++){
        delete [] p[i];
    }
    delete [] p;
    return 0;
}