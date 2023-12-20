#include<bits/stdc++.h>
using namespace std;

int Path_Count(int row, int col)
{
    int i, j ;
    int matrix[row][col], mntable[row][col], mxtable[row][col] ;

    for(i=row-1; i>=0; i--)
    {
        for(j=col-1; j>=0; j--)
        {
            if(i==row-1 || j==col-1)
                matrix[i][j] = 1 ;

            else if (i%2!=0)
                matrix[i][j] = matrix[i][j+1] + matrix[i+1][j] ;

            else
                matrix[i][j] = matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1] ;

        }
    }

    return matrix[0][0] ;
}

int Calc_Min_Cost(int **arr, int row, int col)
{
    int dptable[row][col] , i, j ;

    for(i=row-1; i>=0; i--)
    {
        for(j=col-1; j>=0; j--)
        {
            if(i==row-1 && j==col-1)
                dptable[i][j] = arr[i][j] ;

            else if(i==row-1 && j!=col)
                dptable[i][j] = arr[i][j] + dptable[i][j+1] ;

            else if(j==col-1 && i!=row-1)
                dptable[i][j] = arr[i][j] + dptable[i+1][j] ;

            else if (i%2!=0)
                dptable[i][j] = arr[i][j] + min(dptable[i+1][j],dptable[i][j+1]) ;

            else
            {
                int mn = min(dptable[i+1][j],dptable[i][j+1]) ;
                dptable[i][j] = arr[i][j] + min(mn,dptable[i+1][j+1]) ;
            }
        }
    }

    return dptable[0][0] ;
}

int Calc_Max_Cost(int **arr, int row, int col)
{
    int dptable[row][col] , i, j ;

    for(i=row-1; i>=0; i--)
    {
        for(j=col-1; j>=0; j--)
        {
            if(i==row-1 && j==col-1)
                dptable[i][j] = arr[i][j] ;

            else if(i==row-1 && j!=col)
                dptable[i][j] = arr[i][j] + dptable[i][j+1] ;

            else if(j==col-1 && i!=row-1)
                dptable[i][j] = arr[i][j] + dptable[i+1][j] ;

            else if (i%2!=0)
                dptable[i][j] = arr[i][j] + max(dptable[i+1][j],dptable[i][j+1]) ;

            else
            {
                int mn = max(dptable[i+1][j],dptable[i][j+1]) ;
                dptable[i][j] = arr[i][j] + max(mn,dptable[i+1][j+1]) ;
            }
        }
    }

    return dptable[0][0] ;
}

int main()
{
    int row, col,i,j ;
    cout << "Enter the row and column : " ;
    cin >> row >> col ;

    int **arr = (int**)(malloc(sizeof(int*) *row)) ;

    for(i=0; i<row; i++)
    {
        arr[i] = (int*) (malloc(sizeof(int) * col)) ;
        for(j=0; j<col; j++)
            cin >> arr[i][j] ;
    }

    int ans1 = Path_Count(row,col) ;
    int ans2 = Calc_Min_Cost(arr,row,col);
    int ans3 = Calc_Max_Cost(arr,row,col);

    cout << "Total ways = " << ans1 << endl ;
    cout << "minimum cost = " << ans2<< endl ;
    cout << "maximum cost = " << ans3 << endl ;


}
