/*
https://www.careercup.com/question?id=5652067409461248
https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/
http://ideone.com/JXMl4L
https://ide.geeksforgeeks.org/tiyLThcuSN -> Zero
https://ide.geeksforgeeks.org/3Ks1tpOkwn
*https://code.hackerearth.com/ea07cfD?key=1cb190b158c79639d66d35f7dfa8ef7a -> One
Similr Problem - https://ide.codingblocks.com/s/95965
You’ll be given a grid as below:
    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x
In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.
  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get 
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone 
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:
    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x
  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the 
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. 
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.
    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x
   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/

#include <bits/stdc++.h>
using namespace std;

int maxCoins;
vector<vector<int>> myGrid;

void bombBlast(int r, vector<vector<int>>& grid){
    for(int i=r;i>r-5 && i>=0;i--){
        for(int j=0;j<5;j++){
            if(grid[i][j]==2){
                grid[i][j]=0;
            }
        }
    }
    return;
}

void dfs(int row,int pos,  vector<vector<int>>& grid, bool bombLeft, int csf){
    if(row==-1){
        maxCoins = max(maxCoins, csf);
        return;
    }
    if(grid[row][pos]==2){
        if(bombLeft){
            bombBlast(row,grid);
            dfs(row-1, pos,grid,false,csf);
            if(pos-1>=0) dfs(row-1, pos-1,grid,false,csf);
            if(pos+1<5)  dfs(row-1, pos+1,grid,false,csf);
            grid = myGrid;
        }
        else{
            maxCoins = max(maxCoins, csf);
        }
        return;
    }

    if(grid[row][pos]==1){
        csf++;
    }

    dfs(row-1, pos,grid,bombLeft,csf);
    if(pos-1>=0) dfs(row-1, pos-1,grid,bombLeft,csf);
    if(pos+1<5)  dfs(row-1, pos+1,grid,bombLeft,csf);

    return;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> grid(n+1,vector<int>(5,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>grid[i][j];
            }
        }
        myGrid = grid;

        maxCoins = 0;

        dfs(n,2, grid,true, 0);

        cout<<maxCoins<<endl;
    }
}