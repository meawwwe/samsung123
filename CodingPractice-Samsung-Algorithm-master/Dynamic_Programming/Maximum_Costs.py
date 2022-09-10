def maxCost(N,costs):
    """
    N=4
    costs = [1,5,6,7]
    maxCost(N,costs)
    """
    dp = [0 for x in range(N+1)]
    for i in range(1,N+1):
        for j in range(1,i+1):
            dp[i] = max(dp[i-j] + costs[j],dp[i])
    return dp[N]

import sys
if __name__ == "__main__":
    N = int(sys.stdin.readline())
    costs = list(map(int,sys.stdin.readline().split()))
    costs = [0]+costs
    print(maxCost(N,costs))
