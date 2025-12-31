t = int(input())

# Time is O(n log n)
for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    s = 0

    # So you can work with pointers O(n log n)
    a.sort()
    ans_ord = []
    ans = 0

    r, l = 0, n-1
    # O(n)
    while len(ans_ord) < n:
        # If by adding the biggest value the level will change add it so you get most points
        lvl = s//x
        if (s+a[l])//x > lvl:
            ans_ord.append(str(a[l]))
            s += a[l]
            ans += a[l]
            l -= 1
        # If doing previous won't change the lvl, add smaller values first so you waste minimum amount of points
        # You keep adding them until you can add the next biggest purchace
        else:
            ans_ord.append(str(a[r]))
            s += a[r]
            r += 1

    print(ans)
    print(' '.join(ans_ord))