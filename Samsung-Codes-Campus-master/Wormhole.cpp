/* Problem Description -- https://www.careercup.com/question?id=5677905146281984 */

/* BACKTRACKING METHOD -- ALL 50 TEST CASES PASSED IN SAMSUNG */

#include <iostream>
using namespace std;

// x and y of source and destination
int src[2];
int dest[2];

//entry (x,y) exit (x,y) and cost of ith wormhole { using struct type was giving some error}
int s1[100],s2[100],d1[100],d2[100],cost[100];

//No of holes, visited holes, ans 
int n;
int visited[100]={false};
int ans;

//find Manhatten distance
int findDistance(int a[],int b[]){
    return abs(a[0]-b[0]) + abs(a[1] -b[1]);
}


void solve(int curr_pos[],int temp_cost)
{
    //check if distance from destination is less than previous selections
    if(ans>temp_cost+findDistance(curr_pos,dest))
        ans=temp_cost+findDistance(curr_pos,dest);
        
    //Recursion termination condition    
    if(curr_pos[0]==dest[0] && curr_pos[1]==dest[1])
    {
        if(temp_cost<ans)
            ans=temp_cost;
        
        return ;    
    }
    
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            int temp1[2],temp2[2];
            
            temp1[0]=s1[i];temp1[1]=s2[i];
            temp2[0]=d1[i];temp2[1]=d2[i];
            
            //cost to reach beginning of ith wormhole( bi directional wormhole)
            int cost1=findDistance(curr_pos,temp1);
            int cost2=findDistance(curr_pos,temp2);
            
            //choose
            visited[i]=true;
            
            //back track in both the direction for optimized solution
            solve(temp2,temp_cost+cost1+cost[i]);
            
            solve(temp1,temp_cost+cost2+cost[i]);
            
            //unchoose
            visited[i]=false;
        }
    }
}

/*
        
        1
        2
        0 0
        100 100
        1 2 120 120 0
        6 8 150 180 0    ---> 43 
        
 */

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        cin>>src[0]>>src[1]>>dest[0]>>dest[1];
        
        for(int i=0;i<n;i++)
            {
                cin>>s1[i]>>s2[i]>>d1[i]>>d2[i]>>cost[i];
            }
            
        for(int i=0;i<100;i++)
            visited[i]=false;
        
        ans=findDistance(src,dest);
        
        solve(src,0);
        
        cout<<ans<<endl;
            
    }   
    
	return 0;
}
