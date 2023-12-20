#include<bits/stdc++.h>
using namespace std;

int coin_change(int arr[], int unit, int n)
{
    int i, j, x, y ;
    int table[n+1][unit+1] ;

    table[0][0] = 1 ;
    for(i=1; i<=unit; i++)
        table[0][i] = 0 ;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<=unit; j++)
        {
            x = table[i-1][j] ;

            if(j-arr[i-1] < 0)
                y = 0 ;
            else
                y = table[i][j-arr[i-1]] ;

            table[i][j] = x + y ;
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=unit; j++)
            cout << table[i][j] << " " ;
        cout << endl ;
    }

    int result = table[n][unit] ;
    return  result ;
}

int main()
{
    int arr[] = {1,2,3,5} ;
    int unit = 7 ;
    int n = sizeof(arr) / sizeof(arr[0]) ;

    int ans = coin_change(arr,unit,n);

    cout << endl << ans << " Ways" << endl ;
    return 0 ;
}
