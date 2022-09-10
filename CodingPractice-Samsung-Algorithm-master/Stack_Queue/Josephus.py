def Josephus(n,m):
    """
    if n=7 nad m=3
    ans=[3,6,2,7,5,1,4]
    """
    arr = []
    for i in range(1,n+1):
        arr.append(i)
    ans = []
    for i in range(n):
        for j in range(m-1):
            arr.append(arr.pop(0))
        ans.append(arr.pop(0))
    return ans
    
