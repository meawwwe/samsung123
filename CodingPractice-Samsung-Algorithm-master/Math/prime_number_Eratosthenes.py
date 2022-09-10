#Sieve of Eratosthenes
def find_prime(n):
    p = []
    c = [False for x in range(n+1)]
    for i in range(2,n+1):
        if c[i]==False:
            p.append(i)
            for j in range(i*i,n+1,i):
                c[j]=True
    return p
