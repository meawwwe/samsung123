// Given a 2d array with size n*m, there's some obstacles placed at some points. 
// A frog trying to jump from the beginning point 0,0 to the bottom right point n-1, m-1.
// Say if a frog can jump maximum k distance a time, what is the minimun steps needed?
// Note: the frog can only jump horizontally or vertically, it can't jump diagonally.
// Obstacles are represented by -1.

// eg:
// [0,0,-1,0,0,0,-1,0,0,0,-1,0], maximum step k = 2

// answer: 6


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};

int bfs(vector<vector<int>>& grid, int k){
    int n = grid.size();
    int m = grid[0].size();
    if(grid[n-1][m-1]==-1) return -1;
    
    queue<int> que;
    que.push(0);
    int level=0;

    vector<int> vis(n*m, false);
    vis[0] = true;

    while(que.size()!=0){
        int size=que.size();
        while(size--){
            int idx = que.front();
            que.pop();

            int i = idx/m;
            int j = idx%m;

            if(i==n-1 && j==m-1){
                return level;
            }

            for(int d=0;d<4;d++){
                int r = i+dir[d][0];
                int c = j+dir[d][1];

                if(r>=0 && c>=0 && r<n && c<m && !vis[r*m + c]){
                    vis[r*m + c] = true;
                    que.push(r*m + c);
                }

            }
        }
        level++;
    }
    return -1;
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    int ans;
    if(grid[n-1][m-1]==-1) ans = -1;
    else{
        ans = bfs(grid,k);
    }
    cout<<ans<<endl;
    return 0;
}
