/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n,1);
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }

    arr.insert(arr.begin(),1);
    arr.push_back(1);
    
    vector<vector<int>> dp(n+2, vector<int>(n+2,0));
    
    for(int g=0;g<n-1;g++){
        for(int i=1,j=1+g; j<=n;i++,j++){
            for(int k=i;k<=j;k++){
                dp[i][j] = max( dp[i][j], dp[i][k-1]+dp[k+1][j]+ arr[i-1]*arr[j+1] );                    
            }
        }
    }
    
    int g=n-1;
    for(int i=1,j=1+g; j<=n;i++,j++){
        for(int k=i;k<=j;k++){
            dp[i][j] = max( dp[i][j], dp[i][k-1]+dp[k+1][j] + arr[k] );                
        }
    }


    cout<<dp[1][n];
    return 0;
}
