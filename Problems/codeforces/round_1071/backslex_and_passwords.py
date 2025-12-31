def solve(kx):
    # in a space width x you can have all letters be the same without having duplicates at j-i%x == 0
    # so the bigger the space (x) the bigger the ans
    # if you have more letters you can make another space of x width
    # so more letters means more space
    # Time O(1)
    k, x = map(int, kx)
    return k*x+1



for _ in range(int(input())):
    print(solve(input().split()))