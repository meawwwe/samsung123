import heapq
"""
sort coor by x-coor
if x-coor are same then
sort coor by y-coor
"""
N = int(input())
h = []
for _ in range(N):
    a,b = map(int,input().split())
    heapq.heappush(h,(a,b))
for _ in range(N):
    info = heapq.heappop(h)
    print(str(info[0])+" "+str(info[1]))
