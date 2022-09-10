def numberOfExp(n):
    dp = [0 for x in range(n+1)]
    dp[0]=1
    for i in range(1,n+1):
        for j in range(1,4):
            if i-j>=0:
                dp[i]+=dp[i-j]
    return dp[n]

if __name__=="__main__":
    T = int(input())
    for i in range(T):
        num = int(input())
        print(numberOfExp(num))
