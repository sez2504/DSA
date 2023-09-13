#include <iostream>
using namespace std;

//int count = 0;
#include <climits>

//BRUTE FORCE
int countMinStepsToOne_helper(int n , int count)
{
	// if (n==1){
    //     return count;
    // }
    // if ((n%2!=0 && n%3!=0) || (n-1)%9==0 || (n-2)%9==0){
    //     int opt1 = countMinStepsToOne_helper(n-1 , count +1);
    //     return opt1;
    // }
    // if(n%3==0){
    //     int opt2= countMinStepsToOne_helper(n/3 , count +1);
    //     return opt2;
    // }
    // else{
    //     int opt2=countMinStepsToOne_helper(n/2 , count+1);
    //     return opt2;
    // }
    //for (int i=0 ; i<)
}

//DP:-
//int count = 0;
#include <climits>

int countStepsToOne(int n){
    int * ans = new int[n+1];
    //memset(ans , INT_MAX , n*sizeof(int));
    for (int i=0 ; i<n+1 ; i++){
        ans[i]=INT_MAX;
    }
    ans[0]=0;
    ans[1]=0;
    for (int i=1 ; i<n+1 ; i++){
        int count = ans[i] + 1;
        if (i+1>=n+1){
            break;
        }
        if (count < ans[i + 1]) {
            ans[i + 1] = count;
        }
        if(2*i>=n+1){
            continue;
        }
        if (count<ans[2*i]){
            ans[2*i]=count;
        }
        if (3*i >= n+1){
            continue;
        }
        if (count<ans[3*i]){
            ans[3*i]=count;
        }
        //return ans[n];
    }
    // for (int i=0 ; i<n+1 ; i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    return ans[n];
    //return countMinStepsToOne_helper(n,  count);
}

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
        z=countStepsToOneMemorization(n/2,ans);
    }
    int output = min(x,min(y,z))+1;
    ans[n]=output;
    return output;
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}