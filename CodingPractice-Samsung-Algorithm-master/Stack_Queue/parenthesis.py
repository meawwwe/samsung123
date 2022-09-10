import sys
r = lambda: sys.stdin.readline().strip()

def isValid(s):
    stack = []
    for ele in s:
        if ele=='(':
            stack.append(ele)
        else:
            if len(stack)==0:
                return "NO"
            stack.pop()
    if len(stack)==0:
        return "YES"
    else:
        return "NO"

N = int(sys.stdin.readline())
for i in range(N):
    print(isValid(sys.stdin.readline().strip()))
