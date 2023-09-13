#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n==0){
        return;
    }
    towerOfHanoi(n-1,  source,  destination ,  auxiliary); //n-1 discs in auxiliary using destination , 1 in source
    cout << source <<" " <<destination<<endl; //1 disc from source to destination
    towerOfHanoi(n-1, auxiliary, source, destination); //n-1 disc from auxiliary to destination using source
}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
