def Base_Conversion_10_N(num,N):
    s = ""
    while num>0:
        s+=str(num%N)
        num//=N
    return s[::-1]
        
def Base_Conversion_N_10(num,N):
    ten = 0
    digit = 0
    while num>0:
        ten+=(num%10)*(N**digit)
        num//=10
        digit+=1
    return ten        
