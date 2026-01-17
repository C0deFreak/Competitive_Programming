for _ in range(int(input())):
    n, m, k = map(int, input().split())
    l, r = 0, 0

    while m > 0:
        if l != k-1 and l <= r:
            m -= l+1
            if m >= 0:
                l+=1
        elif r!=n-k:
            m -= r+1
            if m >= 0:
                r+=1
        else:
            break

    print(r+l+1)