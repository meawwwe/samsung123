// Company wants to explore some of the rare elements for its semiconductor manufacturing.
// Scientists use one vehicle to explore the region in order to find the rare elements.
// The vehicle can move only in explored region where roads have already been constructed.
// The vehicle cannot move on unexplored region where roads are not there.
// In the current situation, rare elements are present in explored region only.
// Unexplored regions do not contain any rare elements. Square region is provided for exploration.
// Roads are represented by 1 and where roads are not present that area is represented by 0.
// Rare elements will only be on the roads where regions have already been explored.
// Vehicle can move in four directions – up, down, left and right. The shortest path for vehicle to a rare element position is called Moving Path.
// The longest of the paths to all rare elements from a region called Longest Distance.
// Scientists need to construct one research center so that the research center will be at the position where the longest path to the rare elements will be shortest.
// This is called Shortest Longest Distance.
// For example, Red, Blue and Green area represents Rare Element area. (2, 2) is represented as Red, (2, 8) is represented as Blue and (7, 8) is represented as Green. So there are three rare elements.
// If research center is constructed at (4, 4) then say distance to Red rare element will be 4, distance to Blue rare element will be 6 and distance to Green rare element will be 7.
// So the Longest distance will be 7.
// Now using the same region above, if research center is constructed at (4, 5) then distance to Red rare element will be 5, distance to Blue rare element will be 5 and distance to Green rare element will be 6. So the Longest distance will be 6. So when research center is constructed at (4, 5) then the longest distance will be shortest. And the value of the Shortest Longest Distance will be 6. This will be the output. There can be multiple locations from where the shortest longest distance can be same. For example if research center is constructed at (5, 5) then still the Shortest Longest distance will be 6. So write a program to find the Shortest Longest Distance.

// Constraints: 
// • The region provided will be square region i.e. NxN (where 5 <= N <= 20).
// • There can be minimum of 2 rare elements and maximum of 4 rare elements, i.e. 2 <= C <= 4.
// • Roads are represented by 1 while no road area is represented by 0.
// • Vehicle can move only on roads in explored area.
// • The rare elements will only be present where road are there.
// Rare elements will not be present where roads are not present.
// • Vehicle can move in UP, DOWN, LEFT and RIGHT directions.
// • The starting index for rare element is considers as 1.

// Input:
// • First line will be the number of test cases. Second line will indicate region area (N) and number of rare elements (C).
// Next C lines will contain the position of rare elements.
// After that N lines will provide the region details where to tell where roads are present and where roads are not present.
// Output:
// • Output #testcase followed by space and then shortest longest distance.

// Sample Input:
// 5
// 5 2
// 4 3
// 3 4
// 1 1 0 0 0
// 1 1 0 0 0
// 1 1 1 1 1
// 1 1 1 0 1
// 1 1 1 1 1
// 8 2
// 5 6
// 6 4
// 1 1 1 1 1 1 0 0
// 1 1 1 1 1 1 1 0
// 1 1 0 1 0 1 1 0
// 1 1 1 1 0 1 1 0
// 1 1 1 1 1 1 1 0
// 1 1 1 1 1 1 1 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 10 3
// 8 2
// 5 3
// 7 1
// 0 0 0 1 1 1 1 1 1 0
// 1 1 1 1 1 1 1 1 1 0
// 1 0 0 1 0 0 0 0 1 0
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 0 1 0 0 1 1
// 1 1 1 1 0 1 0 0 1 1
// 1 1 1 1 0 1 0 0 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 0 0 1 0 0 1 1
// 1 1 1 1 1 1 1 1 1 1
// 15 4
// 11 15
// 15 9
// 1 2
// 14 3
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
// 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
// 20 4
// 13 6
// 20 4
// 1 2
// 17 16
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
// 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
// 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
// 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

// Sample Output:
// #1 1
// #2 2
// #3 2
// #4 12
// #5 15

#include<bits/stdc++.h>
using namespace std;

int bfs(int idx, int tar, vector<vector<int>>& grid){
    if(idx==tar) return 0;
    int n=grid.size();
    queue<int> que;
    que.push(idx);
    int level=0;
    vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
    vector<bool> vis(n*n,false);
    while(que.size()!=0){
        int size = que.size();
        while(size-->0){
            int p = que.front();
            que.pop();

            if(p==tar){
                return level;
            }         

            vis[p]=true;
            for(int d=0;d<4;d++){
                int r = (p/n) + dir[d][0];
                int c = (p%n) + dir[d][1];
                if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==1){
                    if(!vis[r*n + c]){
                        que.push((r*n) + c);
                    }
                }
            }
        }
        level++;
    }
    return -1;
}


int main(){
    int t;
    cin>>t;
    for(int testCase =1; testCase<=t; testCase++){
        int n,c;
        cin>>n>>c;
        vector<vector<int>> grid(n,vector<int>(n));
        vector<vector<int>> target(c,vector<int>(2));
        for(int i=0;i<2*c;i++){
            cin>>target[i/2][i%2];
        }
        for(int i=0;i<n*n;i++){
            cin>>grid[i/n][i%n];
        }
        
        int minLmd=INT_MAX;
        for(int i=0;i<n*n;i++){
            if(grid[i/n][i%n]==1){
                int lmd = -1;
                for(int k=0;k<c;k++){
                    int t = (target[k][0]-1)*n + (target[k][1]-1);
                    int dist = bfs(i,t,grid);
                    if(dist != -1){
                        lmd = max(lmd,dist);
                    }
                }
                if(lmd!=-1){
                    minLmd = min(minLmd,lmd);
                }
            }
        }
        cout<<"#"<<testCase<<" "<<minLmd<<endl;
    }
    return 0;
}