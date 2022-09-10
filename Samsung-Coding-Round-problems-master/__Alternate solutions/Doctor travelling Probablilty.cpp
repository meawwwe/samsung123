#include<iostream>
using namespace std ;
double g[1000][1000] ;

void DFS(int src,int n,int time,double prob,double ans[])
{
    if(time<=0)
    {
        ans[src] += prob ;
        return ;
    }

    for(int i=1;i<=n;i++)
    {
        if(g[src][i])
        {
            prob *= g[src][i] ;
            DFS(i,n,time-10,prob,ans);
            prob /= g[src][i] ;
        }
    }
}

int main()
{
    int t ;
    cin>>t ;
    while(t--)
    {
        int n,m,time ;
        cin>>n>>m>>time ;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j] = 0 ;
            }
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            double p ;
            cin>>u>>v>>p ;
            g[u][v] = p ;
        }
        double ans[n+1] = {0.0} ;
        DFS(1,n,time,1.0,ans);
        int pos = 0;
        double pos_prob = -1;

        for(int i=1;i<=n;i++)
        {
            if(ans[i]>pos_prob)
            {
                pos_prob = ans[i] ;
                pos = i;
            }
        }
        cout<<pos<<" "<<pos_prob<<endl ;
    }
}
