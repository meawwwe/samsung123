def SpecBinary(n):
    """
    Special Binary Number:
    (1).First digit must be 1
    (2).1 cannot be consecutive
    if n digit is 0:
    0 and 1 can be placed at n-1 digit
    if n digit is 1:
    only 0 can be placed at n-1 digit
    """
    dp = [0 for x in range(n+1)]
    dp[0]=0
    dp[1]=1
    for i in range(2,n+1):
        dp[i]=dp[i-1]+dp[i-2]
    return dp[n]

if __name__=="__main__":
    n = int(input())
    print(SpecBinary(n))
