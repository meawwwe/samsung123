import bisect
import random

def proportion(fruit):
    f_arr = []
    acc = 0
    for key in fruit:
        acc+=fruit[key]
        f_arr.append((acc,key))

    #Binary Search
    x = random.randint(1,acc)
    low = 0
    high = len(f_arr)-1
    while low<high:
        mid = low+(high-low)//2
        if x>f_arr[mid][0]:
            low=mid+1
        else:
            high = mid
    return f_arr[low][1]

if __name__ =="__main__":
    fruit = {'banana':10,'apple':20,'strawberry':70}
    s = 0
    a = 0
    b = 0
    total = 100000
    for _ in range(total):
        ans = proportion(fruit)
        if ans=='strawberry':
            s+=1
        if ans=='apple':
            a+=1
        if ans=='banana':
            b+=1
    print('strawberry is: {0} and real is {1}'.format(s/total,fruit['strawberry']/100))
    print('apple is : {0} and real is {1}'.format(a/total,fruit['apple']/100))
    print('banana is : {0} and real is {1}'.format(b/total, fruit['banana']/100))
    
    """
    *Output:
    
    strawberry is: 0.70024 and real is 0.7
    apple is : 0.20024 and real is 0.2
    banana is : 0.09952 and real is 0.1
    """
