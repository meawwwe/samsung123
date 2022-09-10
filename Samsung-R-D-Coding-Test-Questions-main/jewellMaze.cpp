/*
https://blog.csdn.net/lihenair/article/details/17227667
http://www.mamicode.com/info-detail-995985.html
https://www.oipapio.com/cn/article-8650635
https://blog.csdn.net/broadCE/article/details/47959227
--------------------------------------------------------
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. 
You want to pick up the jewels after getting into the maze through the entrance and before getting 
out of it through the exit. You want to get as many jewels as possible, but you don’t want to take 
the same passage you used once.
When locations of a maze and jewels are given, find out the greatest number of jewels you can get 
without taking the same passage twice, and the path taken in this case.
Input
There can be more than one test case in the input file. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).
In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. 
The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
“0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located 
on the upper-most left passage and the exit is located on the lower-most right passage. 
There is no case where the path from the entrance to the exit doesn’t exist.
Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the 
greatest number of jewels that can be picked up. Each test case must be output separately as a empty.
*/

#include <bits/stdc++.h>
using namespace std;

int maxCoins;
vector<vector<int>> grid2;
bool flag;
int n;

void display(vector<vector<int>>& grid){
    int n=grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int si, int sj, vector<vector<int>>& grid, int csf){
    if(grid[si][sj]==2){
        csf++;
    }

    if(si==n-1 && sj==n-1){
        int prev = grid[si][sj];
        grid[si][sj]=3;
        if(csf >= maxCoins ){
            flag=true;
            maxCoins = csf;
            grid2 = grid;
        }
        grid[si][sj]=prev;
    }

    else{
        int prev = grid[si][sj];
        grid[si][sj]=3;

        for(int d=0;d<4;d++){
            int r = si + dir[d][0];
            int c = sj + dir[d][1];

            if(r>=0 && c>=0 && r<n && c<n && (grid[r][c]==2 || grid[r][c]==0)){
                dfs(r,c,grid,csf);
            }
        }
        grid[si][sj]=prev;

    }

}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        grid2 = grid;
        maxCoins = 0;
        flag=false;        

        if(grid[n-1][n-1]==1 || grid[0][0]==1){
            maxCoins = -1;
        }
        else{
            dfs(0 , 0, grid, 0);
        }        

        display(grid2);
        if(flag==false) maxCoins = -1;
        cout<<maxCoins<<endl;
    }
    return 0;
}