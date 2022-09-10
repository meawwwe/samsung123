/*
Mr. Lee has to travel various offices abroad to assist branches of each place. But he has a problem. 
The airfare would be real high as all offices he has to visit are in foreign countries. He wants to visit every 
location only one time and return home with the lowest expense. Help this company-caring man calculate the lowest expense.
Input format
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. 
After that, the test cases as many as T (T ≤ 30) are given in a row. N, the number of offices to visit is given on 
the first row per each test case. At this moment, No. 1 office is regarded as his company (Departure point). 
(1 ≤ N ≤ 12) Airfares are given to move cities in which branches are located from the second row to N number rows.
i.e. jth number of ith row is the airfare to move from ith city to jth city. If it is impossible to move between 
two cities, it is given as zero.
Output format
Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the 
first row per each test case.
Example of Input
3
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
5
9 9 2 9 5
6 3 5 1 5
1 8 3 3 3
6 0 9 6 8
6 6 9 4 8
3
0 2 24
3 0 2
0 4 0
Example of Output
30
18
11
*/

#include <bits/stdc++.h>
using namespace std;

int minCost;
int flag;

void dfsToHome(int s, int csf, vector<int> vis, vector<vector<int>>& grid){
    int n = grid.size();
    if(s==0){
        minCost = min(minCost, csf);
        flag=1;
        return;
    }

    
    for(int i=0;i<n;i++){
        if(vis[i]!=2 && grid[s][i]!=0){
            vis[i] = 2;
            dfsToHome(i, csf + grid[s][i], vis, grid);
            vis[1] = 1;
        }
    }
}

void dfs(int s, vector<vector<int>>& grid, vector<int>& vis, int cVis, int cost){
    int n = grid.size();
    if(cVis == n){
        dfsToHome(s,cost,vis,grid);
        return;
    }

    

    for(int i=0;i<n;i++){
        if(vis[i]==0 && grid[s][i]!=0){
            vis[i] = 1;
            dfs(i, grid, vis, cVis+1, cost + grid[s][i]);
            vis[i] = 0;
        }
    }

    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }

        int ans;

        vector<int> vis(n,0);
        minCost = INT_MAX;
        flag=0;
        vis[0]=1;
        dfs(0,grid, vis,1, 0);

        if(flag==0){
            minCost = -1;
        }
        cout<<minCost<<endl;
    }
    return 0;
}

