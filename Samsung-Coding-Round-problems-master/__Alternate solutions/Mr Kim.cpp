#include<bits/stdc++.h>
using namespace std ;

void func(bool vis[],int n,int pos,int total,int s,int &ans,int x[],int y[])
{
    if(total == n+2 && pos == n+1)
        ans = min(ans,s) ;
    if(!vis[pos])
    {
        vis[pos] = true ;

        for(int i=0;i<n+2;i++)
        {
            if(!vis[i])
            {
                int sum = abs(x[pos] - x[i])+ abs(y[pos]-y[i]) ;
                func(vis,n,i,total+1,s+sum,ans,x,y) ;
            }
        }

        vis[pos] = false ;
    }
}

int main()
{
    int t;
    cin>>t ;
    while(t--)
    {
        int n;
        cin>>n ;
        int x[n+2],y[n+2] ;

        cin>>x[0]>>y[0] ;
        cin>>x[n+1]>>y[n+1] ;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i] ;
        bool vis[n+2] ;
        for(int i=0;i<n+2;i++) vis[i] = false ;
        int ans = 1e9 ;
        func(vis,n,0,1,0,ans,x,y) ;
        cout<<ans<<endl ;
    }

}
