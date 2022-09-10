from itertools import combinations
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
    
if __name__=="__main__":
    N = int(input())
    for _ in range(N):
        nums = list(map(int,input().split()))
        nums = nums[1:]
        combs = list(combinations(nums,2))
        total = 0
        for comb in combs:
            total += gcd(comb[0],comb[1])
        print(total)
