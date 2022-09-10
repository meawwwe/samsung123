/*
https://www.careercup.com/question?id=5740719907012608
https://stackoverflow.com/questions/39673898/divide-array-into-k-contiguos-partitions-such-that-sum-of-maximum-partition-is-m/39675396
http://ideone.com/r60yH4 - Sameer Code
https://www.careercup.com/question?id=5730470801702912
*/

/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil 
mines adjacent to each other and not in between of each others.After distributing them compute the 
difference of oil mines from the company getting highest and company getting lowest. This number 
should be minimum.(then only the distribution can be termed as fair).
Input 
2 
2 4 
6 13 10 2 
2 4 
6 10 13 2 
output 
5
1
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans;

void dfs(int s, vector<int>& ar, int minV, int maxV, int sum, int nodes, vector<bool>& vis){
    if(vis[s]){        
        if(nodes == k-1){
            int newMin = min(minV, sum);
            int newMax = max(maxV, sum);
            ans = min(ans,newMax - newMin);
        }
        return;
    }

    int idx = (s+1)%n;
    vis[s]=true;

    dfs(idx, ar, minV, maxV, sum+ar[s], nodes, vis);

    int newMin = min(minV, sum);
    int newMax = max(maxV, sum);

    dfs(idx, ar, newMin, newMax, ar[s], nodes+1, vis);

    vis[s]=false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>k>>n;
        vector<int> ar(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }

        vector<bool> vis(n,false);
        ans = INT_MAX;
        for(int i=0;i<n;i++){
            dfs(i,ar, INT_MAX, INT_MIN, 0, 0, vis);
        }       

        cout<<ans<<endl;       
    }
    return 0;
}