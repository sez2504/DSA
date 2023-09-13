#include <iostream>
using namespace std;

//int count = 0;
#include <climits>

int countStepsToOneMemorization(int n , int * ans){
    if (n<=1){
        return 0;
    }
    if (ans[n] !=-1){ //output already exists
        return ans[n];
    }

    int x = countStepsToOneMemorization(n-1 , ans);

    int y=INT_MAX , z = INT_MAX;
    if (n%2==0){
        y=countStepsToOneMemorization(n/2,ans);
    }
    if (n%3==0){
        z=countStepsToOneMemorization(n/3,ans);
    }
    int output = min(x,min(y,z))+1;
    ans[n]=output;
    return output;
}

int countStepsToOne(int n){
    int * ans = new int[n+1];
    //memset(ans , INT_MAX , n*sizeof(int));
    for (int i=0 ; i<n+1 ; i++){
        ans[i]=-1;
    }
    return countStepsToOneMemorization(n, ans);
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}