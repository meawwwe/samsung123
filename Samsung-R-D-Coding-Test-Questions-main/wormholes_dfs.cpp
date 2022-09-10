// https://www.geeksforgeeks.org/samsung-interview-experience-set-34-campus-rd-noida/

#include <bits/stdc++.h>
using namespace std;

int minCost;
bool flag;
int n;
vector<vector<int>> w;

int abs(int a){
    if(a<0) return -a;
    return a;
}

int dist(int a, int b, int c, int d){
    return ( abs(a-c) + abs(b-d) );
}

void dfs(int si, int sj, int di, int dj, vector<bool>& vis, int cost){
    if(si==di && sj==dj){
        minCost = min(minCost, cost);
        return;
    }


    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;

            int d;            
            d = dist(si,sj,w[i][0],w[i][1]) + w[i][4];
            dfs(w[i][2],w[i][3],di,dj,vis,cost+d);

            d = dist(si,sj,w[i][2],w[i][3]) + w[i][4];
            dfs(w[i][0],w[i][1],di,dj,vis,cost+d);

            vis[i] = false;
        }
    }
    dfs(di,dj,di,dj,vis,cost+ dist(si,sj,di,dj) );
    
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int si, sj, di, dj;
        cin>>si>>sj>>di>>dj>>n;
        w.resize(n,vector<int>(5));
        for(int i=0;i<n;i++){
            cin>>w[i][0]>>w[i][1]>>w[i][2]>>w[i][3]>>w[i][4];
        }

        flag=false;
        minCost = dist(si,sj,di,dj);
        vector<bool> vis(n);
        dfs(si,sj,di,dj,vis,0);
        cout<<minCost<<endl;
    }
    return 0;
}
