#include<bits/stdc++.h>
int top = -1 ;
using namespace std;

void stack_push(char x, char stck[])
{
    top++ ;
    stck[top] = x ;
}

char stack_pop(char stck[])
{
    char item = stck[top] ;
    top-- ;

    return item ;
}

int checking(string ax, char stck[])
{
    int i , ans ;
    for(i=0; i<ax.size(); i++)
    {
        if(ax[i] == '(' || ax[i] == '[' || ax[i] == '{')
            stack_push(ax[i], stck);

        else if(ax[i] == ')')
        {
            char item = stack_pop(stck) ;

            if(item != '(')
            {
                ans = 5 ;
                break ;
            }
        }
        else if(ax[i] == '}')
        {
            char item = stack_pop(stck) ;

            if(item!= '{')
            {
                ans = 5 ;
                break ;
            }
        }
        else if(ax[i] == ']')
        {
            char item = stack_pop(stck) ;

            if(item!= '[')
            {
                ans = 5 ;
                break ;
            }
        }
    }
    return ans ;
}

int main()
{
    int i, cnt = 0 ;
    string ax ;
    cout << "Enter the Arithmetic Expression : " ;
    cin >> ax ;

    for(i=0; i<ax.size(); i++)
    {
        if(ax[i] == '(' || ax[i] == '[' || ax[i] == '{')
            cnt++ ;
    }
    char stck[cnt] ;

    int ans = checking(ax,stck);

    if(ans == 5)
        cout << endl <<  "The Given Arithmetic Expression is Invalid ! " << endl  ;
    else if(top==-1)
        cout << endl << "The Given Arithmetic Expression is Valid ! " << endl ;
    else
        cout << endl << "The Given Arithmetic Expression is Invalid ! " << endl ;

    return 0 ;
}


