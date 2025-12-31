#get the greatest common denumerator of two numbers

def gcd(n, m):
    # will definitely stop at 1
    while m%n != 0:
        oldn = n
        oldm = m

        m = oldn
        n = oldm%oldn
    
    return n