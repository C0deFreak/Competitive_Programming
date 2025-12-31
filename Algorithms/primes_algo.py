def iprimes_upto(limit):
    is_prime = [True] * limit
    for n in range(2, limit):
        if is_prime[n]:
           yield n
           for i in range(n*n, limit, n): # start at ``n`` squared
               is_prime[i] = False