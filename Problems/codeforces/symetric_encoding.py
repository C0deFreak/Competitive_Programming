def solve(n, secret):
    # get the letters in alphabetical order
    table = list(set(secret))
    table.sort()
    
    ans = ''
    for s in secret:
        # add the mirrored letter of the current letter of the code we are in
        ans += table[-1-table.index(s)]
    
    return ans


for _ in range(int(input())):
    print(solve(int(input()), input()))