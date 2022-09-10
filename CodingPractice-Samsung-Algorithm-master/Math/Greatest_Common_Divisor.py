#Two Element
def GCD(a,b):
    """
    Euclid Algorithm
    """
    if b==0:
        return a
    else:
        return GCD(b,a%b)
    
#Three Element
def GCD_3(a,b,c):
    return GCD(GCD(a,b),c)

#Least Common Multiple
def lcd(a,b):
    g = GCD(a,b)
    return g*(a//g)*(b//g)
