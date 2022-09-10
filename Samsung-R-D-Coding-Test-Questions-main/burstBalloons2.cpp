/*
Leetcode 312
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by numsay nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n,1);
    for(int i=0;i<=n-1;i++){
        cin>>nums[i];
    }
    
    vector<vector<int>> dp(n+2, vector<int>(n+2,0));
    
    for(int g=0;g<n;g++){
        for(int i=1,j=1+g; j<=n;i++,j++){
            for(int k=i;k<=j;k++){
                dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);                    
            }
        }
    }

    cout<<dp[1][n];
    return 0;
}