/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful
2
6 10 40 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 0.774000  
3 0.700000
*/

#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<pair<int,float>>>& graph, int t, vector<float>& ansArr){
    queue<pair<int,float>> que; 
    que.push({0,1});
    int level=0;

    while(que.size()!=0){
        int size = que.size();
        while(size-->0){
            pair<int,float> d = que.front();
            que.pop();
            int idx = d.first;
            float psf = d.second;

            if(level==t){
                ansArr[idx]+=psf;
            }
            if(level>t) return;

            for(pair<int,float> e: graph[idx]){
                que.push({e.first , psf*e.second});
            }
        }
        level+=10;
    }
}

int main() {
    int te;
    cin>>te;
    for(int testCase =1;testCase<=te;testCase++){
        int n,l,t;
        cin>>n>>l>>t;
        vector<vector<pair<int,float>>> graph(n);
        while(l--){
            int x,y;
            float z;
            cin>>x>>y>>z;
            graph[x-1].push_back({y-1,z});
        }
        vector<float> ansArr(n,0.0);

        float maxProb = -1;
        int ansNode = -1;
        bfs(n,graph,t, ansArr);      

        for(int i=0;i<ansArr.size();i++){
            if(ansArr[i] > maxProb){
                maxProb = ansArr[i];
                ansNode = i;
            }
        }
        cout<<ansNode+1<<" "<<maxProb<<endl;      
    }
    return 0;
}