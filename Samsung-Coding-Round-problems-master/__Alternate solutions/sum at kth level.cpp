#include<iostream>
using namespace std ;

int solve(string s, int k)
{
    int level = -1 ;
    int sum = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            level++ ;
        else if(s[i]==')')
            level-- ;
        else
        {
            if(level == k)
                sum+=s[i]-'0' ;
        }
    }
    return sum ;
}

int main()
{
    int t;
    cin>>t ;
    while(t--)
    {
        string s;
        cin>>s;
        int k ;
        cin>>k ;
        cout<<solve(s,k)<<endl ;
    }

}
