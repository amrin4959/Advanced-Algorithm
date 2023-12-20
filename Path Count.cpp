#include<bits/stdc++.h>
using namespace std;

int path_count(int row, int col)
{
    int table[row][col] ;
    int i, j ;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==0 || j == 0)
                table[i][j] = 1 ;
            else
                table[i][j] = table[i-1][j] + table[i][j-1] ;
        }
    }

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
    int r,c ;
    cout << "Enter Number of Rows : " ;
    cin >> r ;
    cout << endl << "Enter Number of Columns : " ;
    cin >> c ;

    int ans = path_count(r,c);

    cout << endl << ans << " Ways" << endl ;
    return 0 ;
}

