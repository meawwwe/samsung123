def numOfTiles(n):
    dp = [0 for x in range(n+1)]
    dp[0]=1
    dp[1]=1
    for i in range(2,n+1):
        dp[i]=dp[i-1]+dp[i-2]
        dp[i]%=10007
    return dp[n]

if __name__=="__main__":
    n = int(input())
    print(numOfTiles(n))
