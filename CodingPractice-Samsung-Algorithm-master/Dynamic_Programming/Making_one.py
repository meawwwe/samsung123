def makeOne(n):
    """
    n is given integer
    make n as 1 by using three mehtods
    (1).divide n by 3
    (2).divide n by 2
    (3).minus 1 to n
    Finally determine minimum number of operation
    """
    dp = [0 for x in range(n+1)]
    dp[1] = 0
    for i in range(2,n+1):
        #Case of -1
        dp[i]=dp[i-1]+1
        #Case of /2 
        if i%2==0:
            tmp = dp[i//2]+1
            if tmp<dp[i]:
                dp[i]=tmp
        #Case of /3
        if i%3==0:
            tmp = dp[i//3]+1
            if tmp<dp[i]:
                dp[i]=tmp
    return dp[n]


if __name__=="__main__":
    n = int(input())
    print(makeOne(n))
