#include<bits/stdc++.h>
using namespace std;

void GCC(int i,int j, vector<vector<char>>& grid){
    vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    
    grid[i][j]='A';

    for(int d=0;d<8;d++){
        int x=i+dir[d][0];
        int y=j+dir[d][1];
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='@'){
            GCC(x,y,grid);
        }
    }
    return;
}

int main(){
    vector<vector<char>> grid{{'*','@','*','@','*'},{'*','*','@','*','*'},{'*','@','*','@','*'},{'*','*','*','*','*'},{'*','*','*','*','*'}};
    int n=grid.size();
    int m=grid[0].size();
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='@'){
                GCC(i,j,grid);
                count++;
            }
        }
    }

    cout<<count<<endl;
    return 0;
}