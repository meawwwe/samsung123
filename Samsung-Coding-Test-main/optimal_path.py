from itertools import permutations
T = int(input())

def to_dictionary(lst,N):
    location = {}
    lst = lst[0]
    location["work"] = [lst[0],lst[1]]
    lst.pop(0)
    lst.pop(0)
    location["home"] = [lst[0],lst[1]]
    lst.pop(0)
    lst.pop(0)
    customer_lst = []
    for i in range(N):
        customer_lst.append([lst[0],lst[1]])
        lst.pop(0)
        lst.pop(0)
    location["customers"] = customer_lst

    return location

def distance(lst1,lst2):
    distance = abs(lst1[0]-lst2[0]) + abs(lst1[1]-lst2[1])
    return distance


for test_case in range(1, T + 1):
    lst = []
    distance_list = set()
    N = int(input())
    lst.append(list(map(int, input().split())))
    location_info = to_dictionary(lst,N)

    for i in permutations(location_info["customers"]):
        path = [location_info["work"],*list(i),location_info["home"]]
        dist = 0
        for j in range(len(path)-1):
            dist += distance(path[j],path[j+1])
        distance_list.add(dist)
    ans = min(distance_list)
    print("#{} {}".format(test_case,ans))




    

    