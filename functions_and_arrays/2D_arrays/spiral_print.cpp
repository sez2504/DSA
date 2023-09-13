#include <iostream>
using namespace std;

void spiralPrint(int **arr, int r, int c)
{
    int rowsPrintedTop=0,rowsPrintedBottom=0;
    int colPrintedLeft=0,colPrintedRight=0;
    while (rowsPrintedTop+rowsPrintedBottom<r || colPrintedLeft+colPrintedRight<c){
        //cout << c-colPrintedRight <<endl;
        if (rowsPrintedTop+rowsPrintedBottom<r){
            for (int j=colPrintedLeft;j<c-colPrintedRight;j++){
            cout<<arr[rowsPrintedTop][j]<<" ";
        }
        rowsPrintedTop++;
        }
        if (colPrintedLeft+colPrintedRight<c){
            for (int j=rowsPrintedTop;j<r-rowsPrintedBottom;j++){
            cout << arr[j][c-colPrintedRight-1]<<" ";
        }
        colPrintedRight++;
        }
        if (rowsPrintedTop+rowsPrintedBottom<r){
            for (int j=c-colPrintedRight-1;j>=colPrintedLeft;j--){
            cout<<arr[r-rowsPrintedBottom-1][j]<<" ";
        }
        rowsPrintedBottom++;
        }
        if (colPrintedLeft + colPrintedRight < c) {
            for (int j=r-rowsPrintedBottom-1;j>=rowsPrintedTop;j--){
            cout << arr[j][colPrintedLeft]<<" ";
        }
        colPrintedLeft++;
        }
    }
    //cout<<rowsPrintedTop<<rowsPrintedBottom<<colPrintedLeft<<colPrintedRight<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}