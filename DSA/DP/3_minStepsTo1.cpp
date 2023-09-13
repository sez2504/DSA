#include <iostream>
using namespace std;
//int count = 0;
int countMinStepsToOne_helper(int n , int count)
{
	if (n==1){
        return count;
    }
    if (n%2!=0 && n%3!=0){
        return countMinStepsToOne_helper(n-1 , count +1);
    }
    if(n%3==0){
        int opt1= countMinStepsToOne_helper(n-1 , count +1);
        int opt2= countMinStepsToOne_helper(n/3 , count +1);
        return min(opt1,opt2);
    }
    else{
        int opt1= countMinStepsToOne_helper(n-1 , count +1);
        int opt2=countMinStepsToOne_helper(n/2 , count+1);
        return min(opt1,opt2);
    }
}

int countMinStepsToOne(int n){
    int count = 0;
    return countMinStepsToOne_helper(n,  count);
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}