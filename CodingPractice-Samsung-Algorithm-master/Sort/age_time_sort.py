import heapq
N = 3
arr = [(21,"Junkyu"),(21,"Dohyun"),(20,"Sunyoung")]
def age_time(N,arr):
    h = []
    for i in range(len(arr)):
        heapq.heappush(h,(arr[i][0],i,arr[i][1]))
    for i in range(N):
        info = heapq.heappop(h)
        print(str(info[0])+" "+info[2])

if __name__=="__main__":
    N = int(input())
    arr = []
    for i in range(N):
        a,b = input().split()
        arr.append((int(a),b))
    age_time(N,arr)
    
