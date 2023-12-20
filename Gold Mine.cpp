#include<bits/stdc++.h>
using namespace std;

int gold_mine(int **arr,int row, int col)
{
    int table[row][col], i, j ;

    for(i=0; i<row; i++)
        table[i][0] = arr[i][0] ;

    for(i=1; i<col; i++)
    {
        for(j=0; j<row; j++)
        {
            if(j==0)
                table[j][i] = max(table[j+1][i-1],table[j][i-1]) + arr[j][i] ;

            else if(j == row-1)
                table[j][i] = max(table[j-1][i-1],table[j][i-1]) + arr[j][i] ;

            else
            {
                int mx1 = max(table[j-1][i-1],table[j][i-1]) ;
                table[j][i] = max(mx1,table[j+1][i-1]) + arr[j][i] ;
            }
        }
    }
    vector<int> v ;
    int mx2 = table[0][col-1] ;
    for(i=0; i<row; i++)
    {
        if(table[i][col-1] >= mx2)
        {
            v.push_back(i+1);
            mx2 = table[i][col-1] ;
        }
    }

    cout << "Output Table --->>>" << endl ;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            cout << table[i][j] << " " ;
        cout << endl ;
    }
    cout << "Maximum Amount of Gold is Found at Row " ;
    for(i=0; i<v.size(); i++)
    {
        cout << v[i] ;
        if(i!=v.size()-1)
            cout << "," ;
    }
    return  mx2 ;
}

int main()
{
    int r, c, i, j, val ;
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

    int ans = gold_mine(arr,r,c) ;

    cout <<  " and Amount of Gold is = " << ans << endl ;
    return 0 ;
}

