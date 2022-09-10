#include<iostream>
using namespace std ;

int solve(int a[],int n)
{
    int dp[n][n] ;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 0 ;
    for(int len = 1;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j = i + len - 1 ;

            for(int k=i;k<=j;k++)
            {
                int leftValue = 1 ;
                int rightValue = 1 ;
                int before = 0;
                int after = 0 ;

                if(i!=0)
                    leftValue = a[i-1] ;
                if(j!=n-1)
                    rightValue = a[j+1] ;
                if(k!=i)
                    before = dp[i][k-1] ;
                if(k!=j)
                    after = dp[k+1][j] ;
                if(leftValue ==1 && rightValue == 1)
                    dp[i][j] = max(dp[i][j],a[k]+before+after) ;
                else
                    dp[i][j] = max(dp[i][j],leftValue*rightValue+before+after) ;
            }
        }
    }
    return dp[0][n-1] ;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n] ;
        for(int i=0;i<n;i++)
            cin>>a[i] ;
        cout<<solve(a,n)<<endl ;
    }
    return 0;
}
