def solve(nm):
    board = []
    ans = 0
    temp = 0
    n, m = map(int, nm)

    for _ in range(n):
        board.append(list(map(int, input().split())))
    
    # For every place in the board we check the diagonal sums
    # O( n*m*max(n,m) )
    for y in range(n):
        for x in range(m):
            # W go down every direction, adding the value to temp and at the end comparing it to ans
            temp = board[y][x]
            xi, yi = x, y
            while yi != n-1 and xi != 0:
                yi += 1
                xi -= 1
                temp += board[yi][xi]
            xi, yi = x, y
            while yi != n-1 and xi != m-1:
                yi += 1
                xi += 1
                temp += board[yi][xi]
            xi, yi = x, y
            while yi != 0 and xi != 0:
                yi -= 1
                xi -= 1
                temp += board[yi][xi]
            xi, yi = x, y
            while yi != 0 and xi != m-1:
                yi -= 1
                xi += 1
                temp += board[yi][xi]
            
            ans = max(ans, temp)
    return ans

for _ in range(int(input())):
    print(solve(input().split()))