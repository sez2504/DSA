#include <iostream>
using namespace std;

/*brute force:-
int minCount(int n)
{
	if (n==0){
		return 0;
	}
	if (n==1){
		return 1;
	}
	int max = pow(n,0.5);
	//cout<<max<<endl;
	int min = 1+minCount(n-1*1);
	for (int i=2 ; i<=max ; i++){
		int count = 1+minCount(n-i*i);
		if (count<min){
			min = count;
		}
	}
	return min;
}*/

//memorization:-
int minCount_helper(int n , int* ans){
	if (n==0){
		return 0;
	}
	if (n==1){
		return 1;
	}
	if (ans[n]!=-1){
		return ans[n];
	}
	int max = pow(n,0.5);
	//cout<<max<<endl;
	int firstIteration = minCount_helper(n-1*1,ans);
	ans[n-1]=firstIteration;
	int min = 1+firstIteration;
	for (int i=2 ; i<=max ; i++){
		int iterators = minCount_helper(n-i*i, ans);
		int count = 1+iterators;
		ans[n-i*i]=iterators;
		if (count<min){
			min = count;
		}
	}
	ans[n]=min;
	return ans[n];
}

int minCount(int n)
{
	int * ans = new int[n+1];
	for (int i=0 ; i<n+1 ; i++){
		ans[i]=-1;
	}
	return minCount_helper(n, ans);
}

/*DP:-
#include <climits>
int minCount(int n)
{
	int * ans = new int[n+1];
	// for (int i=0 ; i<n+1 ; i++){
	// 	ans[i]=INT_MAX;
	// }
	ans[0]=0;
	ans[1]=1;
	for (int i=2 ; i<n+1 ; i++){
		ans[i]=INT_MAX;
		for (int j=1 ; i-(j*j)>=0 ; ++j){
			ans[i]=min(ans[i],ans[i-j*j]);
		}
		ans[i]++;
	}
	int result = ans[n];
	delete [] ans;
	return result;
}*/

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}