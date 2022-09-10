#O(N)
def prime_number(n):
    if n<2:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True

#(O(N))
def prime_number2(n):
    if n<2:
        return False
    for i in range(2,n//2 +1):
        if n%i==0:
            return False
    return True

#(O(sqrt(N))
def prime_number3(n):
    if n<2:
        return False
    for i in range(2,int(n**(1/2))+1):
        if n%i==0:
            return False
    return True
