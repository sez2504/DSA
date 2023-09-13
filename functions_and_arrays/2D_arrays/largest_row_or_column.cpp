#include <iostream>
using namespace std;

void findLargest(int **arr, int n, int m)
{
    int flag=0;
    int sumMax=-2147483648;
    int sumIndex=0;
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=0 ; j<m ; j++){
            sum+=arr[i][j];
        }
        if (sum>sumMax){
            sumMax=sum;
            sumIndex=i;
        }
    }
    for (int i=0;i<m;i++){
        int sum=0;
        for (int j=0 ; j<n ; j++){
            sum+=arr[j][i];
        }
        if (sum>sumMax){
            sumMax=sum;
            sumIndex=i;
            flag++;
        }
    }
    //cout<<flag<<endl;
    if (flag==0){
        cout<<"row"<<" "<<sumIndex<<" "<<sumMax;
    }
    else{
        cout<<"column"<<" "<<sumIndex<<" "<<sumMax;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}