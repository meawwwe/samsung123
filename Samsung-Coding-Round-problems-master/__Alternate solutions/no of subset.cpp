#include<iostream>
using namespace std ;

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
        int res[(1<<n)][n] ; // 1<<n = 2^n
        int sum = 0 ;
        for(int i=0 ;i< 1<<n; i++)
        {
            int k=0;
            for(int j=0 ;j<n;j++)
            {
                if(i&(1<<j))
                    res[i][k++] = a[j] ;
            }
            if(k>=2)
                sum+= res[i][0] | res[i][k-1] ;
        }
        cout<< sum <<endl;
    }
}
