#include<iostream>
using namespace std ;

int mat[1000][5] ;

int game(int b,int n)
{
    int a[n][5] ;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i>=b && i<=b+4)
            {
                if(mat[i][j]==2)
                    a[i][j]=0 ;
                else
                    a[i][j] = mat[i][j]  ;
            }
            else
            {
                a[i][j] = mat[i][j]  ;
            }
        }
    }

    int p[5] = {-1,-1,0,-1,-1} ;
    int c[5] = {-1,-1,-1,-1,-1} ;
    int ans = 0 ;

    for(int i = n-1 ;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j] == 2)
            {
                c[j] = -1 ;
                continue ;
            }
            for(int k = max(0,j-1) ; k<=min(j+1,4);k++)
            {
                if(p[k]!=-1)
                {
                    c[j] = max(c[j],a[i][j]+p[k]) ;
                }
            }
            ans = max(ans,c[j]) ;
        }
        for(int x=0;x<5;x++)
                p[x] = c[x] ;
    }
    return ans  ;

}

int main()
{
    int n ;
    cin>>n ;

    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
            cin>>mat[i][j] ;
    int ans = 0;
    for(int i=0;i<=n-5;i++)
        ans = max(ans,game(i,n)) ;

    cout<<ans<<endl ;

}
