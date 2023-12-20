#include<bits/stdc++.h>
using namespace std;

int min_path(int **arr,int row, int col)
{
    int table[row][col], i, j ;

    table[0][0] = arr[0][0] ;
    for(i=1; i<row; i++)
        table[i][0] = table[i-1][0] + arr[i][0] ;

    for(i=1; i<col; i++)
        table[0][i] = table[0][i-1] + arr[0][i] ;

    for(i=1; i<row; i++)
    {
        for(j=1; j<col; j++)
            table[i][j] = min(table[i-1][j],table[i][j-1]) + arr[i][j] ;
    }

    cout << "Output Table --->>>" << endl ;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            cout << table[i][j] << " " ;
        cout << endl ;
    }

    int result = table[row-1][col-1] ;
    return  result ;
}

int main()
{
    int r, c, i, j ;
    cout << "Enter Number of Rows : " ;
    cin >> r ;
    cout << "Enter Number of Columns : " ;
    cin >> c ;

    int **arr = (int**)(malloc(sizeof(int*) * r));

    cout << "Enter the Values : " << endl ;

    for(i=0; i<r; i++)
    {
        arr[i] = (int*)(malloc(sizeof(int) * c));
        for(j=0; j<c; j++)
            cin >> arr[i][j] ;
    }
    cout <<  "Input Table --->>> " << endl ;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            cout << arr[i][j] << " " ;
        cout << endl ;
    }
    cout << endl ;

    int ans = min_path(arr,r,c) ;

    cout << endl <<  "Minimum Cost = " << ans <<  " Unit !" << endl ;
    return 0 ;
}

