import heapq
"""
Sort:
(1). decreasing order of Korean
(2). increasing order of English
(3). decreasing order of Math
(4). increasing order of Name
"""
h = []
N = int(input())
for _ in range(N):
    name, korean,english,math = input().split()
    heapq.heappush(h,(-int(korean),int(english),-int(math),name))

for _ in range(N):
    info = heapq.heappop(h)
    print(info[3])
