#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[], int sum, int n)
{
    int i, j ;
    bool x, y ;
    bool table[n+1][sum+1] ;

    table[0][0] = true ;
    for(i=1; i<=sum; i++)
        table[0][i] = false ;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<=sum; j++)
        {
            x = table[i-1][j] ;

            if(j-arr[i-1] < 0)
                y = false ;
            else
                y = table[i-1][j-arr[i-1]] ;

            table[i][j] = x | y ;
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=sum; j++)
        {
            if(table[i][j] == 0)
                cout << "F" << " " ;
            else
                cout << "T" << " " ;
        }
        cout << endl ;
    }

    bool result = table[n][sum] ;
    return  result ;
}

int main()
{
    int arr[] = {1,3,4,7,10} ;
    int sum ;
    cout << "Enter the Sum Value : " ;
    cin >> sum ;

    int n = sizeof(arr) / sizeof(arr[0]) ;

    bool ans = subset_sum(arr,sum,n);

    if(ans==0)
        cout << endl << "There is No Susbset Exist That Form " << sum << endl ;
    else
        cout << endl << "It is Possible To Form " << sum << endl ;


    return 0 ;
}
