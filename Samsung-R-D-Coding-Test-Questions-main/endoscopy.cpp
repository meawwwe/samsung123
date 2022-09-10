#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, int m, vector<vector<bool>>& vis){
    if(i>=0 && j>=0 && i<n && j<m && !vis[i][j]){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m, r, c, l;
        cin>>n>>m>>r>>c>>l;

        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        if (grid[r][c] == 0)
        {
            cout <<grid[r][c]<< endl;
            continue;
        }

        int count=0;
        int level=1;

        queue<int> que;
        que.push(r*m + c);
        vis[r][c] = true;
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                int idx = que.front();
                int x = idx/m;
                int y = idx%m;
                que.pop();

                count++;

                int g = grid[x][y];

                // go up
                if((g==1 || g==2 || g==4 || g==7) && level+1 <= l){
                    int a = x-1;
                    int b = y;
                    int g2 = grid[a][b];
                    if(isSafe(a,b,n,m,vis) && (g2==1 || g2==2 || g2==5 || g2==6)){
                        vis[a][b] = true;
                        que.push(a*m + b);
                    }
                }

                //go down
                if((g==1 || g==2 || g==5 || g==6) && level+1 <= l){
                    int a = x+1;
                    int b = y;
                    int g2 = grid[a][b];
                    if(isSafe(a,b,n,m,vis) && (g2==1 || g2==2 || g2==4 || g2==7)){
                        vis[a][b] = true;
                        que.push(a*m + b);
                    }
                }

                //go left
                if((g==1 || g==3 || g==6 || g==7) && level+1 <= l){
                    int a = x;
                    int b = y-1;
                    int g2 = grid[a][b];
                    if(isSafe(a,b,n,m,vis) && (g2==1 || g2==3 || g2==4 || g2==5)){
                        vis[a][b] = true;
                        que.push(a*m + b);
                    }
                }

                //go right
                if((g==1 || g==3 || g==4 || g==5) && level+1 <= l){
                    int a = x;
                    int b = y+1;
                    int g2 = grid[a][b];
                    if(isSafe(a,b,n,m,vis) && (g2==1 || g2==3 || g2==6 || g2==7)){
                        vis[a][b] = true;
                        que.push(a*m + b);
                    }
                }
            }
            level++;
        }
        cout<<count<<endl;
    }
    return 0;
}